#include<bits/stdc++.h>
using namespace std;

class LRUCache {
  typedef int key_t;
  typedef int value_t;
  
  size_t capacity;
  size_t size;
  
  struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    
    key_t key;
    value_t value;
    
    Node() {}

    Node(pair<key_t, value_t> p) 
      : key(p.first), value(p.second) {} 

    Node(key_t key, value_t value) 
      : key(key), value(value) {}
  };
  
  Node* data;
  allocator<Node> allocateNodes;
  
  unordered_map<key_t, Node*> keyMap;
  
  Node tail;
  Node head;

  Node* getFront(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    keyMap.erase(node->key);
    return node;
  }
  
  Node* makeNode(key_t key, value_t value) {
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
    if (!keyMap.count(key)) 
      return -1;
    auto node = keyIt->second;
    // Split it up from the chain.
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // Push it into the end of the chain.
    pushBack(node);
    return node->value;
  }
  
  void putValue(key_t key, value_t value) {
    Node* node = nullptr;
    if (keyMap.count(key)) {
      // If we found it in the existing chain, split it up from the chain.
      node = keyIt->second;
      node->value = value;
      node->prev->next = node->next;
      node->next->prev = node->prev;
    } else {
      // Or create a new node.
      if (size == capacity) {
        // If it's already reached the capacity, kick the front node out.
        node = getFront(head.next);
        node->key = key;
        node->value = value;
      } else {
        // Else just make a new one.
        node = makeNode(key, value);
      }
    }
    pushBack(node);
    keyMap.insert({key, node});
  }

public:
  LRUCache(size_t capacity) 
    : capacity(capacity), size(0) {
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
  LRUCache(int capacity) 
    : cap_(capacity) {}
  
  int get(int key) {
    int value = -1; 
    if (dict_.count(key)) {
      it = dict_[key];
      value = it->second->second;
      data_.erase(it->second);
      data_.push_front(make_pair(key, value));
      dict_[key] = data_.begin();
    }
    return value;
  }
  
  void put(int key, int value) {
    auto it = dict_.find(key);
    if (it != dict_.end()) {
      data_.erase(it->second);
    }
    data_.push_front(make_pair(key, value));
    dict_[key] = data_.begin();
    if (dict_.size() > cap_) {
      int rKey = data_.rbegin()->first;
      data_.pop_back();
      dict_.erase(rKey);
    }
  }
  
private:
  int cap_;
  list<pair<int, int>> data_;
  unordered_map<int, list<pair<int, int>>::iterator > dict_;
};

void test() {
  LRUCache cache = LRUCache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;
}

int main() {
  test();
  return 0;
}
