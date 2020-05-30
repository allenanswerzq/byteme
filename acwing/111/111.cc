/* created   : 2020-05-25 17:41:31
 * accepted  : 2020-05-25 23:54:19
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define square(x) (x) * (x)

const int N = 5e5 + 7;
ll a[N];
ll b[N];
ll c[N];
int n, m;
ll t;

void merge(int lo, int md, int hi) {
  int i = lo, j = md + 1;
  for (int k = lo; k <= hi; k++) {
    if (j > hi || (i <= md && b[i] <= b[j])) {
      c[k] = b[i++];
    }
    else {
      c[k] = b[j++];
    }
  }
}

ll go(int lo, int md, int hi) {
  trace("go", lo, md, hi);
  for (int i = md + 1; i <= hi; i++) {
    b[i] = a[i];
  }
  trace(mt(b, hi + 1), lo, md, hi);
  sort(b + md + 1, b + hi + 1);
  merge(lo, md, hi);
  trace(mt(c, hi + 1), lo, md, hi);
  ll ans = 0;
  for (int i = 0; i < min(m, (hi - lo + 1) / 2); i++) {
    ans += square(c[hi - i] - c[lo + i]);
  }
  return ans;
}

void solve() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  b[1] = a[1];
  for (int lo = 1, hi = 1; lo <= n; ) {
    int len = 1;
    while (len) {
      trace(len, lo, hi);
      // [lo ... hi] [hi + 1 ... hi + len]
      ll val = go(lo, hi, min(hi + len, n));
      if (val <= t) {
        for (int k = lo; k <= min(hi + len, n); k++) {
          b[k] = c[k];
        }
        if ((hi += len) >= n) break;
        len *= 2;
      }
      else {
        len /= 2;
      }
    }
    ans++;
    lo = hi + 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
