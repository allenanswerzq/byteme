/* created   : 2020-09-27 22:20:02
 * accepted  : 2020-10-22 22:20:25
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
    if (mp.count(key)) {
      touch(key);
      return node.begin()->second;
    }
    return -1;
  }

  void touch(int key) {
    pair<int, int> x = *mp[key];
    node.erase(mp[key]);
    node.push_front(x);
    mp[key] = node.begin();
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      touch(key);
      node.begin()->second = value;
    }
    else {
      if (node.size() == capacity) {
        mp.erase(node.rbegin()->first);
        node.pop_back();
      }
      node.push_front(make_pair(key, value));
      mp[key] = node.begin();
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
