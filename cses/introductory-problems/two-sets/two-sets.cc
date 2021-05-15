/* created   : 2020-11-01 09:34:58
 * accepted  : 2020-11-01 10:23:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  ll s = n * 1ll * (n + 1) / 2;
  if (s % 2) {
    cout << "NO\n";
    return;
  }
  s = s / 2;
  // 1 2 3 4 5 6 7
  vector<int> a, b;
  for (int i = n; i >= 1; i--) {
    if (s >= i) {
      s -= i;
      a.push_back(i);
    } else {
      b.push_back(i);
    }
  }
  // trace(s, a, b);
  cout << "YES\n";
  assert(s == 0);
  cout << a.size() << "\n";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << (i == a.size() - 1 ? '\n' : ' ');
  }
  cout << b.size() << "\n";
  for (int i = 0; i < b.size(); i++) {
    cout << b[i] << (i == b.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
