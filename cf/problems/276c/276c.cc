/* created   : 2020-04-05 16:37:58
 * accepted  : 2020-04-05 16:52:39
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    cnt[l]++;
    cnt[r + 1]--;
  }
  sort(all(a), greater<int>());
  for (int i = 0; i < n; i++) {
    cnt[i + 1] += cnt[i];
  }
  sort(all(cnt), greater<int>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[i] * 1ll * a[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
