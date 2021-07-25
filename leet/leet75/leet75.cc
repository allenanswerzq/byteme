/* created   : 2020-09-17 16:33:23
 * accepted  : 2020-09-17 16:46:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  void sortColors(vector<int>& A) {
    int n = A.size();
    int p0 = 0;
    int p2 = n - 1;
    int i = 0;
    while (i <= p2) {
      if (A[i] == 0) {
        while (i <= p2 && A[i] == 0) {
          swap(A[p0++], A[i]);
          if (p0 > i) {
            i++;
          }
        }
      }
      else if (A[i] == 2) {
        while (i <= p2 && A[i] == 2) {
          swap(A[p2--], A[i]);
        }
      }
      else {
        i++;
      }
    }
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

vector<int> test(vector<int> a) {
  Solution sol;
  sol.sortColors(a);
  return a;
}

void solve() {
  EXPECT(
      test({2, 2, 0, 0}), vector<int>({0, 0, 2, 2}));

  EXPECT(
      test({1, 2, 2, 2, 1, 1}), vector<int>({1, 1, 1, 2, 2, 2}));

  EXPECT(
      test({2, 0, 2, 1, 1, 0}), vector<int>({0, 0, 1, 1, 2, 2}));

  EXPECT(
      test({2, 0, 1}), vector<int>({0, 1, 2}));

  EXPECT(
      test({0}), vector<int>({0}));

  EXPECT(
      test({1}), vector<int>({1}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
