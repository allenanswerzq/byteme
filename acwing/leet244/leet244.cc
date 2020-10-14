/* created   : 2020-10-14 22:33:00
 * accepted  : 2020-10-14 22:33:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Design a class which receives a list of words in the constructor, and implements a method that takes two words _word1 _and _word2 _and return the shortest distance between these two words in the list. Your method will be called _repeatedly _many times with different parameters.

// Example:
// Assume that words =["practice", "makes", "perfect", "coding", "makes"].

class WordDistance {
  map<string, vector<int>> a;

 public:
  WordDistance(vector<string>& W) {
    for (int i = 0; i < W.size(); i++) {
      a[W[i]].push_back(i);
    }
  }

  int shortest(string w1, string w2) {
    vector<int>& b = a[w1];
    vector<int>& c = a[w2];
    auto i = b.begin(), j = c.begin();
    int ans = INT_MAX;
    while (i != b.end() && j != c.end()) {
      ans = min(ans, abs(*i - *j));
      if (*i < *j) {
        i++;
      }
      else {
        j++;
      }
    }
    return ans;
  }
};


#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
