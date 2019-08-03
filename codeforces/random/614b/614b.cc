/*
 * created   : 2019-07-26 14:47:43
 * accepted  : 2019-07-26 15:05:06
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  auto check = [&](string x) {
    int a = 0;
    int b = 0;
    int nx = (int) x.size();
    for (int i = 0; i < nx; ++i) {
      if (x[i] == '1') {
        a++;
      }
      else if (x[i] == '0') {
        b++;
      }
    }
    return a == 1 && (a + b == nx);
  };
  string ans;
  int zero = 0;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    if (x == "0") {
      ans = x;
      zero = 0;
      break;
    }
    else if (check(x)) {
      zero += (int) x.size() - 1;
    }
    else {
      ans = x;
    }
  }
  if (ans.empty()) {
    cout << "1";
  }
  else {
    cout << ans;
  }
  for (int i = 0; i < zero; ++i) {
    cout << "0";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
