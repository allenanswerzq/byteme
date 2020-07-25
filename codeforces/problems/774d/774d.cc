/* created   : 2020-03-30 19:18:37
 * accepted  : 2020-03-30 19:23:27
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, l, r; cin >> n >> l >> r;
  l--, r--;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  map<int, int> ma, mb;
  for (int i = 0; i < n; i++) {
    if (l <= i && i <= r) {
      ma[a[i]]++;
      mb[b[i]]++;
    }
    else {
      if (a[i] != b[i]) {
        cout << "LIE" << '\n';
        return;
      }
    }
  }
  for (auto it : ma) {
    if (!mb.count(it.x) || it.y != mb[it.x]) {
      cout << "LIE" << '\n';
      return;
    }
  }
  cout << "TRUTH" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
