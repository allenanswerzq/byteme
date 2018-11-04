#include<bits/stdc++.h>
using namespace std;

const int size = 1002;
int n;
int dp[size];
int visit[size];
set<int> st;
unordered_set<int> cycle;
unordered_map<int, set<int>> mp;

void bfs() {
  mp[n + 1] = st; 
  mst(visit, 0);
  deque<int> dq;
  dq.pb(n + 1);
  mst(dp, 0);
  visit[n + 1] = 1;
  // par(visit, n + 2);
  int level = 0;
  while (sz(dq)) {
    int kk = sz(dq); 
    fori (j, 0, kk) {
      auto cur = dq.fr(); dq.ppf();
      // trace(cur, level, j, kk);
      dp[cur] = level;
      fora (e, mp[cur])
        if (visit[e] == 0 && !cycle.count(e)) {
          visit[e] = 1;
          dq.pb(e);
        }
    }
    ++level;
  }
}

void dfs(int x, int parent) {
  if (visit[x] == 1) {
    cycle.insert(x);
    return;
  };
  visit[x] = 1;
  fora (a, mp[x]) {
    if (a != parent)
      dfs(a, x);
  }
}

// Small and large are both accepted.
void solve() {
  n = sz(mp);
  if (n == 3) return;
  cycle.clear();
  fori (i, 1, n + 1) {
    mst(visit, 0);
    dfs(i, -1);
  }
  // pvi(cycle);

  st.clear();
  fora (c, cycle) {
    fora (e, mp[c]) {
      if (!cycle.count(e)) 
        st.insert(e);
    } 
  }
  // pvi(st);
  bfs();
}

int main() {
 
  int t; cin >> t;
  // t = 4;
  fori (i, 1, t + 1) {
    mp.clear();
    mst(dp, 0);
    int n; cin >> n;
    fori (i, 0, n) {
      int a, b; 
      cin >> a >> b; 
      mp[a].insert(b);
      mp[b].insert(a);
    } 
    solve();
    cout << "Case #" << i << ": ";
    fori (j, 1, n + 1)
      cout << dp[j] << " ";
    cout << endl;
  }

  return 0;
}
