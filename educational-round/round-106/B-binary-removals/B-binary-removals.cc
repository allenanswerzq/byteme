/* created   : 2021-12-01 08:07:59
 * accepted  : 2021-12-02 08:33:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

bool check(vector<int> & v) {
  for (int i = 0; i + 1 < v.size(); i++) {
    if (v[i + 1] <= v[i] + 1) {
      return false;
    }
  }
  return true;
}

void solve() {
  // 0000
  // 1111
  // 00001111
  string S; cin >> S;
  vector<int> zero, one;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '0') {
      zero.push_back(i);
    }
    else {
      one.push_back(i);
    }
  }
  if (check(zero) || check(one)) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < S.size(); i++) {
    vector<int> t;
    for (int j : one) {
      if (j <= i) {
        t.push_back(j);
      }
    }
    for (int j : zero) {
      if (j > i) {
        t.push_back(j);
      }
    }
    if (check(t)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
