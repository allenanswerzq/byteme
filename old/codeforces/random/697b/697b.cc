/*
 * created   : 2019-07-26 09:37:00
 * accepted  : 2019-07-26 10:08:41
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
  string s;
  cin >> s;
  int pd = (int) s.find('.');
  int pe = (int) s.find('e');
  string a = s.substr(0, pd);
  string d = s.substr(pd + 1, pe - pd - 1);
  int e = stoi(s.substr(pe + 1));
  trace(a, d, e);
  cout << a;
  int nd = (int) d.size();
  char mx = *max_element(d.begin(), d.end());
  char mi = *min_element(d.begin(), d.end());
  if (mx == mi && mi == '0') {
    nd = 0;
  }
  for (int i = 0; i < min(e, nd); ++i) {
    cout << d[i];
  }
  if (e < nd) {
    cout << ".";
    for (int i = e; i < nd; ++i) {
      cout << d[i];
    }
  }
  for (int i = 0; i < e - nd; ++i) {
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
