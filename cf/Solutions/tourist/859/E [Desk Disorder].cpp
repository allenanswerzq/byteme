/**
 *    author:  tourist
 *    created: 16.09.2017 20:51:39       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector <int> p;
  int n;

  dsu(int n) : n(n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

const int md = 1000000007;

const int N = 1234567;

vector<int> g[N];
int r[N];
int dist[N];
int x[N];

int main() {
  int n;
  scanf("%d", &n);
  dsu d(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    r[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    if (d.unite(x, y)) {
      g[x].push_back(y);
      g[y].push_back(x);
    } else {
      r[x] = y;
    }
  }
  int ans = 1;
  for (int i = 0; i < 2 * n; i++) {
    dist[i] = -1;
  }
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 0; i < 2 * n; i++) {
      if (rot == 0 && r[i] == -1) {
        continue;
      }
      if (dist[i] != -1 || g[i].empty()) {
        continue;
      }
      int b = 0, e = 1;
      x[0] = i;
      dist[i] = 1;
      while (b < e) {
        for (int j : g[x[b]]) {
          if (dist[j] == -1) {
            x[e] = j;
            dist[j] = dist[x[b]] + 1;
            e++;
          }
        }
        b++;
      }
      if (r[i] != -1) {
        ans = (long long) ans * min(2, dist[r[i]]) % md;
      } else {
        ans = (long long) ans * e % md;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
