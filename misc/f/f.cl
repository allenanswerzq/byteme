/* created   : 2021-10-10 11:31:19
 * accepted  : 2021-10-10 11:53:54
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int N;
vector<int> A;
vector<int> cnt;
map<int, int> mp;
vector<vector<int>> g;
vector<int> total_visit;

void dfs(int u, int mx, vector<int>& visit) {
  visit[u] = 1;
  mx = max(mx, A[u]);
  assert(0 <= mx && mx < N);
  cnt[mp[mx]]++;
  for (int v : g[u]) {
    if (visit[v] || total_visit[v]) continue;
    dfs(v, mx, visit);
  }
}

void solve() {
  cin >> N;
  g.resize(N);
  A.resize(N);
  cnt.resize(N);
  total_visit.resize(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    x--;
    A[i] = x;
    mp[x] = i;
  }
  for (int i = 1; i < N; i++) {
    int x; cin >> x;
    x--;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    vector<int> visit(N);
    dfs(i, -1, visit);
    total_visit[i] = 1;
  }
  for (int i = 0; i < N; i++) {
    cout << cnt[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
