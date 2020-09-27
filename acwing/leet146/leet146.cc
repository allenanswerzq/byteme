/* created   : 2020-09-27 22:20:02
 * accepted  : 2020-09-27 22:36:05
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class LRUCache {
 public:
  using iterator = list<pair<int, int>>::iterator;

  LRUCache(int cap) {
    capacity = cap;
  }

  int get(int key) {
    // trace("get", key, node);
    if (mp.count(key)) {
      auto it = mp[key];
      int ans = it->second;
      moveToFront(key, it);
      return ans;
    }
    return -1;
  }

  void moveToFront(int key, const iterator& it) {
    if (it == node.begin()) {
      mp[key] = node.begin();
    }
    else {
      int val = it->second;
      node.erase(it);
      node.insert(node.begin(), {key, val});
      mp[key] = node.begin();
    }
    // trace("moveToFront", key, node);
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      auto it = mp[key];
      *it = {key, value};
      moveToFront(key, it);
    }
    else if (node.size() < capacity) {
      node.push_back({key, value});
      auto it = node.end();
      moveToFront(key, --it);
    }
    else {
      assert(node.size());
      mp.erase(node.back().first);
      node.pop_back();
      node.push_back({key, value});
      moveToFront(key, std::prev(node.end()));
    }
  }

 private:
  int capacity;
  list<pair<int, int>> node;
  unordered_map<int, iterator> mp;
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test() {
  LRUCache lru(2);
  lru.put(1, 1);           // cache is {1=1}
  lru.put(2, 2);           // cache is {1=1, 2=2}
  EXPECT(lru.get(1), 1);   // return 1
  lru.put(3, 3);           // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  EXPECT(lru.get(2), -1);  // returns -1 (not found)
  lru.put(4, 4);           // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  EXPECT(lru.get(1), -1);  // return -1 (not found)
  EXPECT(lru.get(3), 3);   // return 3
  EXPECT(lru.get(4), 4);   // return 4
}

void solve() { test(); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
