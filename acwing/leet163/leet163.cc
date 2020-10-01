/* created   : 2020-10-01 09:15:12
 * accepted  : 2020-10-01 18:08:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

// Have you met this question in a real interview?
// Example
// Example 1

// Input:
// nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
// Output:
// ["2", "4->49", "51->74", "76->99"]
// Explanation:
// in range[0,99],the missing range includes:range[2,2],range[4,49],range[51,74] and range[76,99]
// Example 2

// Input:
// nums = [0, 1, 2, 3, 7], lower = 0 and upper = 7
// Output:
// ["4->6"]
// Explanation:
// in range[0,7],the missing range include range[4,6]

class Solution {
public:
  vector<string> findMissingRanges(vector<int>& A, int S, int T) {
    assert(S <= T);
    vector<ll> B(A.begin(), A.end());
    if (B.empty() || B.back() != T) {
      B.push_back((ll) T + 1);
    }
    vector<string> ans;
    int n = B.size();
    ll s = S;
    for (int i = 0; i < n;) {
      if (s == B[i]) {
        while (i < n && B[i] == s) i++;
        s++;
      }
      else {
        string t;
        t.append(to_string(s));
        if (B[i] - 1 > s) {
          t.append("->");
          t.append(to_string(B[i] - 1));
        }
        s = B[i];
        ans.push_back(t);
      }
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

vector<string> test(vector<int> A, int S, int T) {
  Solution sol;
  return sol.findMissingRanges(A, S, T);
}

void solve() {
  trace(test({-2147483648,-2147483648,0,2147483647,2147483647}, -2147483648, 2147483647));
  trace(test({1}, -2147483648, 2147483647));
  trace(test({}, -2147483648, 2147483647));
  trace(test({1, 2, 3, 4, 5, 6, 7, 8}, 1, 9));
  trace(test({}, 1, 1));
  trace(test({0, 1, 3, 50, 75}, 0, 99));
  trace(test({0, 1, 2, 3, 7}, 0, 7));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
