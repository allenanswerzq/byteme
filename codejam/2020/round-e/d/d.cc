/* created   : 2020-08-27 22:41:00
 * accepted  : 2020-08-29 23:01:09
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 330;
ll stone_dist[N][N];
pair<int, ll> recipe_dist[N][N];

struct Node {
  ll dist;
  int kind;
  int cur;
  bool operator< (const Node& b) const {
    return dist > b.dist;
  }
};

void solve() {
  int V, E, S, R; cin >> V >> E >> S >> R;
  trace(V, E, S, R);
  vector<vector<int>> g(V);
  for (int e = 0; e < E; e++) {
    int u, v; cin >> u >> v; u--, v--;
    trace(u, v, V);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> have(V);
  for (int i = 0; i < V; i++) {
    int c; cin >> c;
    have[i].resize(c);
    for (int& s : have[i]) {
      cin >> s; s--;
    }
  }
  vector<vector<int>> uses(S);
  vector<int> num_inputs(R);
  vector<int> become(R);
  for (int r = 0; r < R; r++) {
    cin >> num_inputs[r];
    for (int k = 0; k < num_inputs[r]; k++) {
      int s; cin >> s; s--;
      uses[s].push_back(r);
    }
    cin >> become[r];
    become[r]--;
  }
  memset(stone_dist, 0x3f, sizeof(stone_dist));
  memset(recipe_dist, 0, sizeof(recipe_dist));
  priority_queue<Node, vector<Node>> qu;
  for (int i = 0; i < V; i++) {
    for (int s : have[i]) {
      stone_dist[s][i] = 0;
      qu.push(Node{stone_dist[s][i], s, i});
    }
  }
  while (!qu.empty()) {
    Node tp = qu.top(); qu.pop();
    ll dist = tp.dist;
    int kind = tp.kind;
    int cur = tp.cur;
    trace(dist, kind, cur);
    if (dist > stone_dist[kind][cur]) continue;
    for (int r : uses[kind]) {
      recipe_dist[r][cur].first++;
      recipe_dist[r][cur].second += dist;
      if (recipe_dist[r][cur].first == num_inputs[r]) {
        ll nd = recipe_dist[r][cur].second;
        int t = become[r];
        if (nd < stone_dist[t][cur]) {
          stone_dist[t][cur] = nd;
          qu.push(Node{nd, t, cur});
        }
      }
    }
    for (int nxt : g[cur]) {
      ll nd = dist + 1;
      if (nd < stone_dist[kind][nxt]) {
        stone_dist[kind][nxt] = nd;
        qu.push(Node{nd, kind, nxt});
      }
    }
  }
  const ll INF = 1e12;
  ll ans = INF;
  for (int i = 0; i < V; i++) {
    ans = min(ans, stone_dist[0][i]);
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
