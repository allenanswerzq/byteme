/* created   : 2022-02-13 10:37:41
 * accepted  : 2022-02-13 16:32:33
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void amin(ll& a, ll b) { a = min(a, b); }

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  vector<ll> X(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> X[i];
  }
  vector<ar> to(2 * K + 3);
  vector<vector<ar>> row(N + 1);
  // node id for the new graph
  int cnt = 0;
  row[1].push_back({1, cnt++});
  for (int i = 0; i < K; i++) {
    ll a, b, c, d, h; cin >> a >> b >> c >> d >> h;
    row[a].push_back({b, cnt++});
    row[c].push_back({d, cnt++});
    // (a, b) --> (c, d)
    // trace(i, cnt - 2, cnt - 1, -h);
    to[cnt - 2] = {cnt - 1, -h};
  }
  row[N].push_back({M, cnt});
  trace(row);
  trace(to);
  const ll INF = 1e18;
  vector<ll> f(2 * K + 3, INF);
  f[0] = 0;
  for (int i = 1; i <= N; i++) {
    sort(all(row[i]));
    int c = row[i].size();
    trace(i, f);
    for (int j = 0; j + 1 < c; j++) {
      // j --> j + 1
      ll u = row[i][j][1];
      ll v = row[i][j + 1][1];
      amin(f[v], f[u] + X[i] * abs(row[i][j][0] - row[i][j + 1][0]));
    }
    for (int j = c - 1; j >= 1; j--) {
      // j --> j - 1
      ll u = row[i][j][1];
      ll v = row[i][j - 1][1];
      amin(f[v], f[u] + X[i] * abs(row[i][j][0] - row[i][j - 1][0]));
    }
    for (int j = 0; j < c; j++) {
      // u --> v
      ll u = row[i][j][1];
      if (f[u] != INF) {
        // If it can reach u
        ll v = to[u][0];
        amin(f[v], f[u] + to[u][1]);
      }
    }
  }
  trace(f);
  if (f[cnt] == INF) {
    cout << "NO ESCAPE" << "\n";
  }
  else {
    cout << f[cnt] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
