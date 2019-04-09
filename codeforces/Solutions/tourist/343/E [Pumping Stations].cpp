#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 123456;

int ss[N], ff[N], c[N], f[N], obr[N], pred[N], last[N], d[N], x[N];
int n, m, st, fin;

void add(int x, int y, int z, int xx, int yy) {
  m++;
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  obr[m] = yy;
}

bool expath() {
  for (int i = 1; i <= n; i++) d[i] = -1;
  int b = 1, e = 1;
  x[1] = st;
  d[st] = 0;
  while (b <= e) {
    int j = last[x[b]];
    while (j > 0) {
      if (c[j] > f[j] && d[ff[j]] == -1) {
        e++;
        x[e] = ff[j];
        d[x[e]] = d[x[b]] + 1;
        if (x[e] == fin) break;
      }
      j = pred[j];
    }
    if (x[e] == fin) break;
    b++;
  }
  return (d[fin] != -1);
}

int rec(int v, int w) {
  if (v == fin) return w;
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

int qs[N], qf[N], qd[N];
int es[N], ef[N], ed[N];
int g[N];
int idg[N], idv[N];
int qlast[N];
int user[N];
int num[N];
bool good[N];
int mx, km;
const int inf = (int)1e9;

void dfs(int v, int pr) {
  int j = last[v];
  while (j > 0) {
    if (good[num[j]]) {
      if (ef[j] != pr) {
        if (ed[j] < mx) {
          mx = ed[j];
          km = j;
        }
        dfs(ef[j], v);
      }
    }
    j = pred[j];
  }
}

bool first;

void solve(int v) {
  mx = inf; km = 0;
  dfs(v, 0);
  if (mx == inf) {
    if (!first) printf(" ");
    first = false;
    printf("%d", v);
    return;
  }
  good[num[km]] = false;
  int qm = km;
  solve(es[qm]);
  solve(ef[qm]);
}

int main() {
  int nn, mm;
  scanf("%d %d", &nn, &mm);
  for (int i = 1; i <= mm; i++) {
    scanf("%d %d %d", qs + i, qf + i, qd + i);
  }
  int kg = 1;
  for (int i = 1; i <= nn; i++) g[i] = 1;
  while (kg < nn) {
    int vs = -1, vf = -1;
    for (int i = 1; i <= nn; i++) {
      for (int j = i + 1; j <= nn; j++)
        if (g[i] == g[j]) {
          vs = i;
          vf = j;
          break;
        }
      if (vs != -1) break;
    }
    n = 0;
    for (int i = 1; i <= nn; i++)
      if (g[i] == g[vs]) idv[i] = ++n;
    for (int i = 1; i <= kg; i++)
      if (i != g[vs]) idg[i] = ++n;
    m = 0;
    for (int i = 1; i <= mm; i++) {
      int from = qs[i], to = qf[i];
      if (g[from] == g[vs]) from = idv[from];
      else from = idg[g[from]];
      if (g[to] == g[vs]) to = idv[to];
      else to = idg[g[to]];
      add(from, to, qd[i], 0, m + 2);
      add(to, from, qd[i], 0, m);
    }
    for (int i = 1; i <= n; i++) last[i] = 0;
    for (int i = 1; i <= m; i++) {
      pred[i] = last[ss[i]];
      last[ss[i]] = i;
    }
    for (int i = 1; i <= n; i++) qlast[i] = last[i];
    st = idv[vs];
    fin = idv[vf];
    int flow = 0;
    while (expath()) {
      int t = rec(st, 1000000);
      flow += t;
      for (int i = 1; i <= n; i++) last[i] = qlast[i];
    }
    for (int i = 1; i <= nn; i++)
      if (g[i] == g[vs] && d[idv[i]] == -1) g[i] = kg + 1;
    es[kg] = g[vs];
    ef[kg] = kg + 1;
    ed[kg] = flow;
    for (int i = 1; i < kg; i++) {
      if (es[i] == g[vs] && d[idg[ef[i]]] == -1) es[i] = kg + 1;
      if (ef[i] == g[vs] && d[idg[es[i]]] == -1) ef[i] = kg + 1;
    }
    kg++;
  }
  n = nn;
  for (int i = 1; i <= n; i++) user[g[i]] = i;
  for (int i = 1; i <= n - 1; i++) {
    es[i] = user[es[i]];
    ef[i] = user[ef[i]];
  }
  for (int i = 1; i <= n - 1; i++) {
    es[i + n - 1] = ef[i];
    ef[i + n - 1] = es[i];
    ed[i + n - 1] = ed[i];
    num[i + n - 1] = num[i] = i;
    good[i] = true;
  }
  for (int i = 1; i <= n; i++) last[i] = 0;
  for (int i = 1; i <= n + n - 2; i++) {
    pred[i] = last[es[i]];
    last[es[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) ans += ed[i];
  printf("%d\n", ans);
  first = true;
  solve(1);
  printf("\n");
  return 0;
}
