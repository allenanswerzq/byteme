/* created   : 2020-08-30 08:07:52
 * accepted  : 2020-08-30 09:19:43
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amin(int& a, int b) { a = min(a, b); }

int compare(int a, int b) {
  if (a == b) return 0;
  return a < b ? -1 : 1;
}

// @Solution: dynamic programming

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  };
  vector<int> f(4);
  for (int i = 1; i < n; i++) {
    vector<int> nf(4, n + 1);
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        amin(nf[y], f[x] + (compare(x, y) != compare(a[i - 1], a[i])));
      }
    }
    f = nf;
  }
  int ans = *min_element(all(f));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
