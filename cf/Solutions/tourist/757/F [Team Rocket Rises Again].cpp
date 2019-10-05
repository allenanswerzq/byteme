#include <bits/stdc++.h>

using namespace std;

const long long md = 981168724994134051LL;

inline void add(long long &x, long long y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

const long long inf = (long long) 1e18;
const int N = 1234567;

vector < pair <int, int> > gd[N];
vector <int> g[N];
long long d[N];
int pos[N];

long long f[N], h[N];
int hit[N];
bool was[N];
int x[N];

int main() {
  int n, m, st;
  scanf("%d %d %d", &n, &m, &st);
  st--;
  for (int i = 0; i < m; i++) {
    int foo, bar, baz;
    scanf("%d %d %d", &foo, &bar, &baz);
    foo--; bar--;
    gd[foo].push_back(make_pair(bar, baz));
    gd[bar].push_back(make_pair(foo, baz));
  }
  set < pair <long long, int> > s;
  for (int i = 0; i < n; i++) {
    d[i] = (i == st ? 0LL : inf);
    s.insert(make_pair(d[i], i));
  }
  vector <int> order;
  while (!s.empty()) {
    int i = (*(s.begin())).second;
    if (d[i] == inf) {
      break;
    }
    pos[i] = order.size();
    order.push_back(i);
    s.erase(s.begin());
    int sz = gd[i].size();
    for (int j = 0; j < sz; j++) {
      int u = gd[i][j].first;
      int len = gd[i][j].second;
      if (d[i] + len < d[u]) {
        s.erase(make_pair(d[u], u));
        d[u] = d[i] + len;
        s.insert(make_pair(d[u], u));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int sz = gd[i].size();
    for (int j = 0; j < sz; j++) {
      int u = gd[i][j].first;
      int len = gd[i][j].second;
      if (d[i] != inf && d[u] != inf && d[i] + len == d[u]) {
        g[i].push_back(u);
      }
    }
  }
  int cnt = order.size();
  for (int id = 0; id < cnt; id++) {
    f[order[id]] = 0;
  }
  f[order[0]] = 1;
  for (int id = 0; id < cnt; id++) {
    int i = order[id];
    int sz = g[i].size();
    for (int j = 0; j < sz; j++) {
      int u = g[i][j];
      add(f[u], f[i]);
    }
  }
  for (int id = 0; id < cnt; id++) {
    was[order[id]] = false;
  }
  for (int i = 0; i < n; i++) {
    h[i] = i;
    hit[i] = -1;
  }
  int ans = 0;
  for (int id = 1; id < cnt; id++) {
    int i = order[id];
    if (was[i]) {
      continue;
    }
    int b = 0, e = 1;
    x[0] = i;
    h[i] = f[i];
    hit[i] = id;
    while (b < e) {
      int sz = g[x[b]].size();
      for (int j = 0; j < sz; j++) {
        int u = g[x[b]][j];
        if (hit[u] != id) {
          hit[u] = id;
          h[u] = 0;
        }
        add(h[u], h[x[b]]);
        if (!was[u] && h[u] == f[u]) {
          was[u] = true;
          x[e++] = u;
        }
      }
      b++;
    }
    ans = max(ans, e);
  }
  printf("%d\n", ans);
  return 0;
}
