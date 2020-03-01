/* created   : 2020-02-29 00:00:49
 * accepted  : 2020-02-29 22:21:13
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

void solve() {
  int n, k, l, r, sa, sk;
  cin >> n >> k >> l >> r >> sa >> sk;
  vector<int> a(n);
  int a1 = sk / k;
  int e1 = sk - a1 * k;
  int a2 = (k < n ? (sa - sk) / (n - k) : 0);
  int e2 = (k < n ? (sa - sk) - a2 * (n - k) : 0);
  for (int i = 0; i < n; i++) {
    if (i < k) {
      a[i] = a1;
    }
    else {
      a[i] = a2;
    }
  }
  for (int i = 0; i < k && e1 > 0; i++) {
    int d = min(r - a[i], e1);
    a[i] += d;
    e1 -= d;
  }
  int mi = 1e6 + 7;
  for (int i = 0; i < k; i++) {
    mi = min(a[i], mi);
  }
  for (int i = k; i < n && e2 > 0; i++) {
    int d = min(mi - a[i], e2);
    a[i] += d;
    e2 -= d;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    assert(l <= a[i] && a[i] <= r);
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
    sum += a[i];
  }
  assert(sum == sa);
  trace(a);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
