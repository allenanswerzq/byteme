/* created   : 2020-04-12 16:44:30
 * accepted  : 2020-04-12 17:19:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q; cin >> q;
  vector<pair<int, int>> query;
  for (int i = 0; i < q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int p, x; cin >> p >> x;
      p--;
      query.push_back({p, x});
    }
    else {
      int x; cin >> x;
      query.push_back({-1, x});
    }
  }
  vector<bool> use(n);
  int mx = 0;
  for (int i = q - 1; i >= 0; i--) {
    if (query[i].x == -1) {
      mx = max(mx, query[i].y);
    }
    else {
      int p = query[i].x;
      trace(i, a[i], mx, query[i]);
      if (!use[p]) {
        a[p] = max(mx, query[i].y);
        use[p] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      a[i] = max(a[i], mx);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
