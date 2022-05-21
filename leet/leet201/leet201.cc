/* created   : 2020-10-02 17:45:57
 * accepted  : 2020-10-02 18:02:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    while (m < n) {
      m >>= 1;
      n >>= 1;
      i++;
    }
    return (m << i);
  }
};
