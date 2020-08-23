/* created   : 2020-08-23 07:08:46
 * accepted  : 2020-08-23 09:44:01
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// TODO(): wrong answer

struct Discreter {
  vector<int> e;
  vector<int> a;
  unordered_map<int, int> t;
  int mx = 0;
  bool one_index = true;

  Discreter(vector<int>& v) {
    a = v;
    e = v;
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (const auto& x : v) {
      int p = lower_bound(all(e), x) - e.begin() + one_index;
      mx = max(mx, p);
      t[x] = p;
    }
  }

  int at(int x) { return a[x]; }

  int size() { return mx; }

  // Given a raw value, returns the discreted value.
  int get_dis(int x) { return t[x]; }

  // Given a discreted value, return the raw value.
  int get_raw(int x) { return e[x - one_index]; }
};

struct RangeSegment {
  vector<int> L;
  vector<int> R;
  // which segment the index `i` locates.
  vector<int> pos;
  int seg_num = 0;

  RangeSegment(int n, int seg_num_) : seg_num(seg_num_) {
    assert(seg_num);
    int t = n / seg_num;
    if (seg_num * t < n) {
      seg_num++;
    }
    trace(seg_num, t, n);
    L.resize(seg_num + 1);
    R.resize(seg_num + 1);
    pos.resize(n + 1);
    // [1...t][t + 1...2 * t]
    for (int i = 1; i <= seg_num; i++) {
      L[i] = (i - 1) * t + 1;
      R[i] = min(i * t, n);
    }
    for (int i = 1; i <= seg_num; i++) {
      for (int j = L[i]; j <= R[i]; j++) {
        pos[j] = i;
      }
    }
  }

  int segment_id(int x) {
    assert(x < pos.size());
    return pos[x];
  }
};

const int N = 4e4 + 7;
const int T = 38;
int cnt[T][T][N];
array<int, 2> f[T][T];

void do_work(Discreter& dis, int x, int y, int lo, int hi, array<int, 2>* ans) {
  for (int i = lo; i <= hi; i++) {
    int val = dis.get_dis(dis.at(i));
    cnt[x][y][val]++;
    int& cur = cnt[x][y][val];
    trace(x, y, val, cur, i, dis.at(i), lo, hi, *ans);
    if (cur > (*ans)[0] || (cur == (*ans)[0] && val < (*ans)[1])) {
      (*ans) = {cur, val};
    }
  }
  for (int i = lo; i <= hi; i++) {
    int val = dis.get_dis(dis.at(i));
    cnt[x][y][val]--;
  }
}

int query(RangeSegment& rs, Discreter& dis, int l, int r) {
  int p = rs.segment_id(l);
  int q = rs.segment_id(r);
  int x = 0, y = 0;
  // p x x q
  if (p + 1 <= q - 1) {
    x = p + 1;
    y = q - 1;
  }
  array<int, 2> ans = f[x][y];
  if (p == q) {
    do_work(dis, x, y, l, r, &ans);
  }
  else {
    do_work(dis, x, y, l, rs.R[p], &ans);
    do_work(dis, x, y, rs.L[q], r, &ans);
  }
  return dis.get_raw(ans[1]);
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Discreter dis(a);
  trace(a, dis.e, dis.t);
  int seg_num = pow(n, 1.0 / 3);
  RangeSegment rs(n, seg_num);
  trace(n, m, rs.seg_num);
  for (int i = 1; i <= rs.seg_num; i++) {
    for (int j = i; j <= rs.seg_num; j++) {
      for (int k = rs.L[i]; k <= rs.R[j]; k++) {
        cnt[i][j][dis.get_dis(a[k])]++;
      }
      for (int k = 1; k <= dis.size(); k++) {
        if (cnt[i][j][k] > f[i][j][0]) {
          f[i][j][0] = cnt[i][j][k];
          f[i][j][1] = k;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    l = (l + ans - 1) % n + 1;
    r = (r + ans - 1) % n + 1;
    if (l > r) swap(l, r);
    ans = query(rs, dis, l, r);
    trace(l, r, ans);
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
