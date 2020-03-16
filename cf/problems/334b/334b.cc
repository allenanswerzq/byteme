/* created   : 2020-03-16 09:42:24
 * accepted  : 2020-03-16 10:09:35
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  vector<int> x(8);
  vector<int> y(8);
  set<pair<int, int>> st;
  for (int i = 0; i < 8; i++) {
    cin >> x[i] >> y[i];
    st.insert({x[i], y[i]});
  }
  set<int> sx(all(x));
  set<int> sy(all(y));
  if ((int) sx.size() != 3 || (int) sy.size() != 3) {
    cout << "ugly" << '\n';
    return;
  }
  vector<int> xx(all(sx));
  vector<int> yy(all(sy));
  trace(xx, yy);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      trace(i, j, xx[i], yy[j]);
      if (i == 1 && j == 1) {
        if (st.count({xx[1], yy[1]})) {
          trace(st, xx[i], yy[j]);
          cout << "ugly" << '\n';
          return;
        }
      }
      else if (!st.count({xx[i], yy[j]})) {
        trace(i, j, xx[i], yy[j]);
        cout << "ugly" << '\n';
        return;
      }
    }
  }
  cout << "respectable" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
