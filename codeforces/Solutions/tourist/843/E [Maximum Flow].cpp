#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

const int N = 200010;

struct flow_graph {

  int sta, fin;
  int ss[N], ff[N], c[N], f[N], obr[N], pred[N], last[N], st[N];
  int n;
  int m;

  flow_graph(int nnn, int S, int T) {
    n = nnn;
    sta = S;
    fin = T;
    for (int i = 0; i < n; i++) {
      last[i] = 0;
    }
  }

  void add(int x, int y, int z, int xx, int yy) {
    m++;
    ss[m] = x;
    ff[m] = y;
    c[m] = z;
    f[m] = xx;
    obr[m] = yy;
    pred[m] = last[x];
    last[x] = m;
  }

  void add(int x, int y, int z) {
    add(x, y, z, 0, m + 2);
    add(y, x, 0, 0, m);
  }

  int x[N], d[N];

  bool expath() {
    for (int i = 0; i < n; i++) d[i] = -1;
    int b = 1, e = 1;
    x[1] = sta;
    d[sta] = 0;
    while (b <= e) {
      int j = last[x[b]];
      while (j > 0) {
        if (c[j] > f[j] && d[ff[j]] == -1) {
          e++;
          x[e] = ff[j];
          d[x[e]] = d[x[b]] + 1;
          if (x[e] == fin) {
            return true;
          }
        }
        j = pred[j];
      }
      b++;
    }
    return false;
  }

  int rec(int v, int w) {
    if (v == fin) {
      return w;
    }
    int r = 0, j = last[v];
    while (j > 0) {
      last[v] = pred[j];
      if (c[j] > f[j] && d[ff[j]] == d[v] + 1) {
        int ww = c[j] - f[j];
        if (w - r < ww) ww = w - r;
        int t = rec(ff[j], ww);
        if (t > 0) {
          f[j] += t;
          if (obr[j] != 0) f[obr[j]] -= t;
          r += t;
          if (r == w) break;
        }
      }
      j = pred[j];
    }
    return r;
  }

  long long max_flow() {
    for (int i = 0; i < n; i++) {
      st[i] = last[i];
    }
    long long ans = 0;
    while (expath()) {
      int t = rec(sta, inf);
      ans += t;
      for (int i = 0; i < n; i++) {
        last[i] = st[i];
      }
    }
    return ans;
  }

  set < pair <int, int> > min_cut() {
    set < pair <int, int> > ret;
    for (int i = 1; i <= m; i++) {
      if (c[i] > 0 && d[ss[i]] != -1 && d[ff[i]] == -1) {
        ret.emplace(ss[i], ff[i]);
      }
    }
    return ret;
  }
};

const int MAGIC = (int) 1.01e6;

int from[N], to[N], flag[N];

int main() {
  int nn, mm, ss, tt;
  scanf("%d %d %d %d", &nn, &mm, &ss, &tt);
  ss--; tt--;
  for (int i = 0; i < mm; i++) {
    scanf("%d %d %d", from + i, to + i, flag + i);
    from[i]--; to[i]--;
  }
  flow_graph g1(nn, ss, tt);
  for (int i = 0; i < mm; i++) {
    g1.add(from[i], to[i], flag[i] == 0 ? inf : 1);
    if (flag[i] == 1) {
      g1.add(to[i], from[i], inf);
    }
  }
  long long ans = g1.max_flow();
  cout << ans << endl;
  set < pair <int, int> > cut = g1.min_cut();
  flow_graph g2(nn + 2, nn, nn + 1);
  for (int i = 0; i < mm; i++) {
    if (!flag[i]) {
      continue;
    }
    int bound = inf - 1;
    if (cut.find(make_pair(from[i], to[i])) != cut.end()) {
      bound = MAGIC;
    }
    g2.add(nn, to[i], 1);
    g2.add(from[i], nn + 1, 1);
    g2.add(from[i], to[i], bound - 1);
  }
  g2.add(tt, ss, inf);
  g2.max_flow();
  map < pair <int, int>, int > mp;
  for (int i = 1; i <= g2.m; i++) {
    if (g2.f[i] > 0) {
      if (g2.ss[i] == tt || g2.ff[i] == ss) {
        continue;
      }
      mp[make_pair(g2.ss[i], g2.ff[i])] += g2.f[i];
    }
  }
  for (int i = 0; i < mm; i++) {
    if (flag[i] == 0) {
      printf("%d %d\n", 0, 1);
      continue;
    }
    int f = 1 + mp[make_pair(from[i], to[i])];
    if (cut.find(make_pair(from[i], to[i])) != cut.end()) {
      printf("%d %d\n", f, f);
      continue;
    }
    printf("%d %d\n", f, inf);
  }
  return 0;
}
