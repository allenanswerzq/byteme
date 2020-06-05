/* created   : 2020-06-05 17:45:42
 * accepted  : 2020-06-05 19:27:40
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  vector<ll> ps(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
  }
  trace(a, ps);
  deque<int> qu;
  qu.push_back(0);
  ll ans = INT_MIN;
  for (int i = 1; i <= n; i++) {
    while (qu.size() && i - qu.front() > m) {
      qu.pop_front();
    }
    assert(qu.size());
    ans = max(ans, ps[i] - ps[qu.front()]);
    trace(ans, i, qu.front());
    while (qu.size() && ps[i] <= ps[qu.back()]) {
      qu.pop_back();
    }
    qu.push_back(i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
