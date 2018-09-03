#include<bits/stdc++.h>
using namespace std;



template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

class LRUCache {
  typedef int key_t;
  typedef int value_t;
  
  size_t capacity;
  size_t size;
  
  struct Node {
  Node * next = nullptr;
  Node * prev = nullptr;
  
  key_t key;
  value_t value;
  
  Node() {}
  
  Node(pair<key_t, value_t> p) : key(p.first), value(p.second) {} 
  
  Node(key_t key, value_t value) : key(key), value(value) {}
  };
  
  Node * data;
  allocator<Node> allocateNodes;
  
  unordered_map<key_t, Node*> keyMap;
  
  Node tail;
  Node head;

  Node * getFront(Node * node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  
  keyMap.erase(node->key);
  return node;
  }
  
  Node * makeNode(key_t key, value_t value) {
  allocateNodes.construct(&data[size], Node(key, value));
  return &data[size++];
  }
  
  void pushBack(Node * node) {
  tail.prev->next = node;
  node->prev = tail.prev;
  tail.prev = node;
  node->next = &tail; 
  }
  
  value_t getKey(key_t key) {
  auto keyIt = keyMap.find(key);
  if (keyIt == keyMap.end())
    return -1;
  auto node = keyIt->second;
  node->prev->next = node->next;
  node->next->prev = node->prev;
  
  pushBack(node);
  
  return node->value;
  }
  
  void putValue(key_t key, value_t value) {
  auto keyIt = keyMap.find(key);
  Node * node = nullptr;
  if (keyIt != keyMap.end()) {
    node = keyIt->second;
    node->value = value;
    node->prev->next = node->next;
    node->next->prev = node->prev;
  } else {
    if (size == capacity) {
      node = getFront(head.next);
      node->key = key;
      node->value = value;
    } else {
      node = makeNode(key, value);
    }
  }
  pushBack(node);
  
  keyMap.insert({key, node});
  }

public:
  LRUCache(size_t capacity) : capacity(capacity), size(0) {
  data = allocateNodes.allocate(capacity);
  tail.prev = &head;
  head.next = &tail;
  
  keyMap.reserve(capacity);
  }
  
  ~LRUCache() {
  allocateNodes.deallocate(data, capacity);
  }
  
  value_t get(key_t key) {
  return getKey(key);
  }
  
  void put(key_t key, value_t value) {
  return putValue(key, value);
  }
};

class LRUCache{
public:
  LRUCache(int capacity) : cap_(capacity) {}
  
  int get(int key) {
   int ans = -1; 
   auto it = dic.find(key);
   if (it != dic.end()) {
     ans = it->second->second;
     data_.erase(it->second);
     data_.push_front(make_pair(key, ans));
     dic[key] = data_.begin();
   }
   return ans;
  }
  
  void put(int key, int value) {
  auto it = dic.find(key);
  if (it != dic.end()) {
    data_.erase(it->second);
  }
  data_.push_front(make_pair(key, value));
  dic[key] = data_.begin();
  if (dic.size() > cap_) {
    int rKey = data_.rbegin()->first;
    data_.pop_back();
    dic.erase(rKey);
  }
  }
  
private:
  int cap_;
  list< pair<int, int> > data_;
  unordered_map<int, list< pair<int, int> >::iterator > dic;
};

// TODO
// class LRUCache {
// public:
//   LRUCache(int aa) {
//   }

//   int get(int key) {
//   }
  
//   void put(int key, int value) {
//   }

// private:
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p146-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  LRUCache cache = LRUCache( 2 /* capacity */ );

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2) << endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cout << cache.get(1) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3
  cout << cache.get(4) << endl;       // returns 4


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
