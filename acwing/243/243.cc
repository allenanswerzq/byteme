/* created   : 2020-08-03 07:45:06
 * accepted  : 2020-08-03 08:29:54
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-x))
#define ll long long

struct Bit {
  vector<ll> bt;
  int n;

  Bit(int n_) : n(n_) {
    bt.resize(n + 1);
  }

  void add(int x, int a) {
    for (; x <= n; x += lowbit(x)) {
      bt[x] += a;
    }
  }

  ll query(int x) {
    ll ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += bt[x];
    }
    return ans;
  }

  ll query(int l, int r) {
    assert(l >= 1);
    // assert(l <= r);
    return query(r) - query(l - 1);
  }
};

const int N = 2e5 + 7;
ll lt[N];
ll rt[N];
int a[N];
int n;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Bit b1(n);
  for (int i = n; i >= 1; i--) {
    rt[i] = b1.query(a[i] + 1, n);
    b1.add(a[i], 1);
  }
  Bit b2(n);
  for (int i = 1; i <= n; i++) {
    lt[i] = b2.query(a[i] + 1, n);
    b2.add(a[i], 1);
  }
  ll v = 0;
  for (int i = 1; i <= n; i++) {
    v += lt[i] * rt[i];
  }
  // trace(mt(lt, n + 1), mt(rt, n + 1), v);
  Bit b3(n);
  for (int i = n; i >= 1; i--) {
    rt[i] = b3.query(1, a[i] - 1);
    b3.add(a[i], 1);
  }
  Bit b4(n);
  for (int i = 1; i <= n; i++) {
    lt[i] = b4.query(1, a[i] - 1);
    b4.add(a[i], 1);
  }
  ll u = 0;
  for (int i = 1; i <= n; i++) {
    u += lt[i] * rt[i];
  }
  cout << v << " " << u << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
