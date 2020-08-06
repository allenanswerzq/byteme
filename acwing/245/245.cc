/* created   : 2020-08-06 07:21:06
 * accepted  : 2020-08-06 08:00:28
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define lowbit(x) (x & -x)

struct Bit {
  vector<ll> b;
  int n;

  Bit(int n_) : n(n_) {
    b.resize(n + 1);
  }

  void add(int x, int val) {
    for (; x <= n; x += lowbit(x)) {
      b[x] += val;
    }
  }

  ll query(int x) {
    ll ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += b[x];
    }
    return ans;
  }
};

const int N = 1e5;
int a[N];

void solve() {
  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  Bit bt(n);
  for (int i = 1; i <= n; i++) {
    bt.add(i, 1);
  }
  // 01111
  vector<int> ans(n + 1);
  for (int i = n; i >= 1; i--) {
    int lo = 0;
    int hi = n + 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      if (bt.query(md) >= a[i] + 1) {
        hi = md;
      }
      else {
        lo = md;
      }
    }
    trace(lo, hi, bt.query(lo), bt.query(hi), a[i] + 1);
    bt.add(hi, -1);
    ans[i] = hi;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
