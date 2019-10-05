#include<bits/stdc++.h>
using namespace std;

const int size = 110;
ll grid[size][size];
ll path[size][size];
int n_vertices;

void singleShortPathDijstra(int src) {

  path[src][src] = 0;
  // par(path[src], n_vertices);
  priority_queue<pii, vpii, greater<pii>> pq;
  pq.push({0, src});
  while (sz(pq)) {
    auto cur = pq.top(); pq.pop(); 
    int u = cur.se;
    fori (v, 0, n_vertices) {
      int t = path[src][u] + grid[u][v];
      if (grid[u][v] && v != u && 
          path[src][u] + grid[u][v] < path[src][v]) {
        path[src][v] = t;
        pq.push({t, v});
      }
    }    
  }
}

void shortPathDijstra() {
  fori (i, 0, n_vertices)
    fori (j, 0, n_vertices)
      if (i == j) path[i][j] = 0;
      else path[i][j] = inf;

  fori (i, 0, n_vertices)
    singleShortPathDijstra(i);
}

void shortPathNaive() {
  fori (i, 0, n_vertices)
    fori (j, 0, n_vertices)
      if (i == j) path[i][j] = 0;
      else if (grid[i][j]) path[i][j] = grid[i][j];
      else path[i][j] = inf;

  fori (i, 0, n_vertices)
    fori (j, 0, n_vertices)
      fori (k, 0, n_vertices) {
        if (k != i && k != j && path[i][k] + path[k][j] < path[i][j]) {
          // trace(i, j, k);
          path[i][j] = path[i][k] + path[k][j];
        }
      }
}

// const int maxn = 200;
// // dp[i][j] denotes the expected value we can get if 
// // we start at `ith` node and we want to catch j.
// double dp[120][maxn];

// double go(int pp) {
//   fori (i, 0, 120)
//     fori (j, 0, maxn)
//       dp[i][j] = 0;

//   double prob = 1.0 / (n_vertices - 1);
//   fori (p, 1, pp + 1) {
//     fori (i, 0, n_vertices) {
//       double res = 0;
//       fori (k, 0, n_vertices) {
//         if (k != i)
//           res += prob * path[i][k]  +  prob * dp[k][p - 1];
//       }
//       dp[i][p] = res;
//     }
//   }
//   return dp[0][pp];
// }

const int maxn = 300;
// dp[i][j] denotes the expected value we can get if 
// we start at `ith` node and we want to catch j.
vector<double> pre;
vector<double> cur;

double go(int pp) {
  pre.clear();
  cur.clear();
  pre.resize(maxn, 0);
  cur.resize(maxn, 0);

  double prob = 1.0 / (n_vertices - 1);
  fori (p, 1, pp + 1) {
    fori (i, 0, n_vertices) {
      double res = 0;
      fori (k, 0, n_vertices) {
        if (k != i)
          res += prob * path[i][k]  +  prob * pre[k];
      }
      cur[i] = res;
    }
    pre = cur;
    // par(pre, n_vertices);
  }
  return pre[0];
}

// Dynamic programing.
umap<ll, double> mp;
double dfs(int start, int p) {
  ll key = start * 10000 + p;
  // trace(key, start, p);
  if (mp.count(key)) return mp[key];

  if (p == 1) {
    int sum = 0;
    fori (i, 0, n_vertices) sum += path[start][i];
    return 1.0 * sum / (n_vertices - 1);
  }

  double res = 0;
  double prob = 1.0 / (n_vertices - 1);
  fori (i, 0, n_vertices) {
    if (i != start) {
      res += prob * path[start][i] + prob * dfs(i, p - 1);
    }
  }
  mp[key] = res; 
  return res;
}

double solve(int p) {
  // shortPathNaive();
  shortPathDijstra();

  // mp.clear();
  // double r = dfs(0, p);
  double r = go(p);
  return r;
}

int main() {
 
  int t; cin >> t;
  // t = 2;
  fori (i, 1, t + 1) {
    mst(grid, 0);
    mst(path, 0);
    int n, m, p; cin >> n >> m >> p;
    fori (j, 0, m) {
      int a, b, c; cin >> a >> b >> c;
      grid[a - 1][b - 1] = c;
      grid[b - 1][a - 1] = c;
    }
    n_vertices = n;
    double r = solve(p);
    output(i, r);
  }

  return 0;
}
