/* created   : 2020-10-04 17:39:19
 * accepted  : 2020-10-04 17:40:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  vector<int> majorityElement(vector<int>& A) {
    int one = 0, count_one = 0;
    int two = 1, count_two = 0;
    for (int x : A) {
      if (x == one) {
        count_one++;
      }
      else if (x == two) {
        count_two++;
      }
      else if (count_one == 0) {
        one = x, count_one = 1;
      }
      else if (count_two == 0) {
        two = x, count_two = 1;
      }
      else {
        count_one--,  count_two--;
      }
    }
    vector<int> ans;
    count_one = 0, count_two = 0;
    for  (int x : A) {
      if (x == one) {
        count_one++;
      }
      else if (x == two) {
        count_two++;
      }
    }
    if (count_one > A.size() / 3) ans.push_back(one);
    if (count_two > A.size() / 3) ans.push_back(two);
    return ans;
  }
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
