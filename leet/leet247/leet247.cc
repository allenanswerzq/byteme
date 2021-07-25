/* created   : 2020-10-15 22:27:33
 * accepted  : 2020-10-15 23:01:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Find all strobogrammatic numbers that are of length = n.

// Have you met this question in a real interview?
// Example
// Example 1:

// Input: n = 2,
// Output: ["11","69","88","96"]
// Example 2:

// Input: n = 1,
// Output: ["0","1","8"]

class Solution {
public:
  vector<char> s = {'6', '9', '0', '8', '1'};
  vector<char> t = {'9', '6', '0', '8', '1'};
  vector<string> ans;

  void dfs(int i, int j, string& path) {
    if (i > j) {
      ans.push_back(path);
    }
    else {
      for (int k = 0; k < s.size(); k++) {
        if (s[k] != '0' || i || i == j) {
          path[i] = s[k];
          path[j] = t[k];
          if (i < j || s[k] == t[k]) {
            dfs(i + 1, j - 1, path);
          }
        }
      }
    }
  }

  vector<string> findStrobogrammatic(int n) {
    string path(n, '0');
    dfs(0, n - 1, path);
    return ans;
  }
};

void test(int n) {
  Solution sol;
  auto ans = sol.findStrobogrammatic(n);
  trace(ans);
}

void solve() {
  test(1);
  test(2);
  test(3);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
