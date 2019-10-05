/* created   : 2019-08-13 11:46:14
 * accepted  : 2019-08-13 15:34:44
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  map<string, int> mp;
  for (int i = 0; i < m; i++) {
    string x;
    cin >> x;
    mp[x]++;
  }
  vector<int> b;
  for (auto it : mp) {
    b.push_back(it.y);
  }
  sort(b.begin(), b.end(), greater<int>());
  trace(b);
  int nb = (int) b.size();
  assert(nb <= n);
  int mi = 0;
  for (int i = 0; i < nb; i++) {
    mi += b[i] * a[i];
  }
  int mx = 0;
  for (int i = 0; i < nb; i++) {
    mx += b[i] * a[n - i - 1];
  }
  cout << mi << " " << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
