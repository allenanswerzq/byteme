/* created   : 2020-03-29 09:44:48
 * accepted  : 2020-03-29 10:30:42
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#endif
typedef long long ll;

struct Node {
  int l, r, p;
};

ostream& operator<<(ostream& os, const Node& a) {
  return os << a.l << ' ' << a.r << ' ' << a.p;
}

bool comp(const Node& a, const Node& b) {
  if (a.l == b.l) {
    return a.r < b.r;
  }
  else {
    return a.l < b.l;
  }
}

void solve() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n; cin >> n;
  vector<int> day;
  for (int i = 1; i <= 12; i++) {
    int t = 28;
    if (set<int>{1, 3, 5, 7, 8, 10, 12}.count(i)) {
      t = 31;
    }
    else if (set<int>{4, 6, 9, 11}.count(i)) {
      t = 30;
    }
    day.push_back(t);
  }
  trace(day);
  vector<int> pr(13);
  for (int i = 0; i < 12; i++) {
    pr[i + 1] = pr[i] + day[i];
  }
  trace(pr);
  vector<Node> a(n);
  for (int i = 0; i < n; i++) {
    int m, d, p, t; cin >> m >> d >> p >> t;
    m = pr[m - 1] + d;
    a[i].l = m - t;
    a[i].r = m - 1;
    a[i].p = p;
  }
  trace(a);
  sort(all(a), comp);
  trace(a);
  // -----|
  //   -----|
  int ans = 0;
  int free = 0;
  vector<bool> done(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (!done[j] && a[j].r < a[i].l) {
        done[j] = true;
        free += a[j].p;
      }
    }
    if (free >= a[i].p) {
      free -= a[i].p;
    }
    else {
      ans += a[i].p - free;
      free = 0;
    }
  }
  cout << ans << '\n';
}

void solve2() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n; cin >> n;
  vector<int> day;
  for (int i = 1; i <= 12; i++) {
    int t = 28;
    for (auto x : {1, 3, 5, 7, 8, 10, 12}) {
      if (x == i) {
        t = 31;
        break;
      }
    }
    for (auto x : {4, 6, 9, 11}) {
      if (x == i) {
        t = 30;
        break;
      }
    }
    day.push_back(t);
  }
  trace(day);
  vector<int> pr(13);
  for (int i = 0; i < 12; i++) {
    pr[i + 1] = pr[i] + day[i];
  }
  trace(pr);
  vector<Node> a;
  for (int i = 0; i < n; i++) {
    int m, d, p, t; cin >> m >> d >> p >> t;
    m = pr[m - 1] + d;
    a.push_back({m - t, -1, p});
    a.push_back({m - 1, 1, p});
  }
  trace(a);
  sort(all(a), comp);
  trace(a);
  int ans = 0;
  int free = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i].r == -1) {
      if (free >= a[i].p) {
        free -= a[i].p;
      }
      else {
        ans += a[i].p - free;
        free = 0;
      }
    }
    else {
      free += a[i].p;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
