/* created   : 2020-08-04 08:02:36
 * accepted  : 2020-08-04 08:37:28
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define lowbit(x) x & (-x)
#define ll long long

struct Bit {
  vector<ll> bt;
  int n;

  Bit(int n_): n(n_) {
    bt.resize(n + 1);
  }

  void add(int x, int d) {
    for (; x <= n; x += lowbit(x)) {
      bt[x] += d;
    }
  }

  ll query(int x) {
    ll ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += bt[x];
    }
    return ans;
  }
};

const int N = 1e5 + 7;
int a[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Bit bt(n + 1);
  for (int i = 1; i <= m; i++) {
    char op; cin >> op;
    if (op == 'C') {
      int l, r, d; cin >> l >> r >> d;
      bt.add(l, d);
      bt.add(r + 1, -d);
    }
    else {
      int p; cin >> p;
      assert(1 <= p && p <= n);
      cout << bt.query(p) + a[p] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
