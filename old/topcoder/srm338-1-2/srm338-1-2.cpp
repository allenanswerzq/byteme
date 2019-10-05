//=============================================================
// Name        : srm338-1-2
// Date        : Sat Jun 15 10:45:31 CST 2019
// Accepted    : Sat Jun 15 11:10:30 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

class InformFriends {
public:
  int maximumGroups(vector<string> matr) {
    int n = matr.size();
    vector<int> inform_all(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
      // How many people can group `i` inform to?
      int mask = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          mask |= (1 << j);
          for (int k = 0; k < n; ++k) {
            if (matr[j][k] == 'Y') {
              mask |= (1 << k);
            }
          }
        }
      }
      inform_all[i] = (mask == (1 << n) - 1);
    }
    vector<int> dp(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
      dp[i] = 0;
      for (int j = i; j > 0; j = (j - 1) & i) {
        if (inform_all[j]) {
          dp[i] = max(dp[i], dp[i ^ j] + 1);
        }
      }
    }
    trace(dp);
    return *max_element(dp.begin(), dp.end());
  }
};

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  InformFriends go;
  int ans = go.maximumGroups(a);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
