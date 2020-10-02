/* created   : 2020-10-02 09:25:43
 * accepted  : 2020-10-02 09:56:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Design and implement a TwoSum class. It should support the following operations: add and find.

// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.

// Have you met this question in a real interview?
// Example
// Example 1:

// add(1); add(3); add(5);
// find(4) // return true
// find(7) // return false

class TwoSum {
public:
  void add(int number) {
    mp[number]++;
  }

  bool find(int value) {
    for (auto& it : mp) {
      auto p = mp.find(value - it.first);
      if (p == mp.end()) continue;
      if (p->first != it.first) {
        return true;
      }
      else if (p->first == it.first) {
        if (p->second > 1) return true;
      }
    }
    return false;
  }

private:
  unordered_map<int, int> mp;
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
