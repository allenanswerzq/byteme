#include <bits/stdc++.h>

using namespace std;

template<typename T>
class hungarian {
  public:
  int n;
  int m;
  vector< vector<T> > a;
  vector<T> u;
  vector<T> v;
  vector<int> pa;
  vector<int> pb;
  vector<int> way;
  vector<T> minv;
  vector<bool> used;
  T inf;

  hungarian(int _n, int _m) : n(_n), m(_m) {
    assert(n <= m);
    a = vector< vector<T> >(n, vector<T>(m));
    u = vector<T>(n + 1);
    v = vector<T>(m + 1);
    pa = vector<int>(n + 1, -1);
    pb = vector<int>(m + 1, -1);
    way = vector<int>(m, -1);
    minv = vector<T>(m);
    used = vector<bool>(m + 1);
    inf = numeric_limits<T>::max();
  }

  inline void add_row(int i) {
    fill(minv.begin(), minv.end(), inf);
    fill(used.begin(), used.end(), false);
    pb[m] = i;
    pa[i] = m;
    int j0 = m;
    do {
      used[j0] = true;
      int i0 = pb[j0];
      T delta = inf;
      int j1 = -1;
      for (int j = 0; j < m; j++) {
        if (!used[j]) {
          T cur = a[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= m; j++) {
        if (used[j]) {
          u[pb[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    } while (pb[j0] != -1);
    do {
      int j1 = way[j0];
      pb[j0] = pb[j1];
      pa[pb[j0]] = j0;
      j0 = j1;
    } while (j0 != m);
  }

  inline T current_score() {
    return -v[m];
  }

  inline T solve() {
    for (int i = 0; i < n; i++) {
      add_row(i);
    }
    return current_score();
  }
};

int friday[42][42];
int saturday[42][42];
int ans;
int n;

void dfs(hungarian<int> &h, int i, int fridays, int saturdays) {
  if (i == n) {
    ans = max(ans, -h.current_score());
    return;
  }
  vector<int> old_u, old_v, old_pa, old_pb, old_way;
  for (int rot = 0; rot < 2; rot++) {
    if (rot == 0 && fridays == n / 2) {
      continue;
    }
    if (rot == 1 && saturdays == n / 2) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      h.a[i][j] = -(rot == 0 ? friday[i][j] : saturday[i][j]);
    }
    old_u = h.u;
    old_v = h.v;
    old_pa = h.pa;
    old_pb = h.pb;
    old_way = h.way;
    h.add_row(i);
    dfs(h, i + 1, fridays + (rot == 0), saturdays + (rot == 1));
    h.u = old_u;
    h.v = old_v;
    h.pa = old_pa;
    h.pb = old_pb;
    h.way = old_way;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", friday[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", saturday[i] + j);
    }
  }
  hungarian<int> h(n, n);
  ans = 0;
  dfs(h, 0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
