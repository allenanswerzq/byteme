/*
 * created   : 2019-07-31 23:00:09
 * accepted  : 2019-07-31 23:10:40
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  vector<pair<string, string>> a = {
    {"127", "byte"},
    {"32767", "short"},
    {"2147483647", "int"},
    {"9223372036854775807", "long"},
    {"XXXXXXX", "BigInteger"}
  };
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++) {
    if (s.size() < a[i].x.size()) {
      cout << a[i].y << "\n";
      return;
    }
    else if (s.size() == a[i].x.size()) {
      if (s <= a[i].x) {
        cout << a[i].y << "\n";
      }
      else {
        cout << a[i + 1].y << "\n";
      }
      return;
    }
  }
  cout << "BigInteger" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
