#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


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
  deque<int> q;
  q.pb(n + 1);
  mst(dp, 0);
  visit[n + 1] = 1;
  // par(visit, n + 2);
  int level = 0;
  while (sz(q)) {
    int kk = sz(q); 
    fori (j, 0, kk) {
      auto cur = q.fr(); q.ppf();
      // trace(cur, level, j, kk);
      dp[cur] = level;
      fora (e, mp[cur])
        if (visit[e] == 0 && !cycle.count(e)) {
          visit[e] = 1;
          q.pb(e);
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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2018-roundc-a-small.txt", "rt", stdin);
  clock_t begin = clock();

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

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
