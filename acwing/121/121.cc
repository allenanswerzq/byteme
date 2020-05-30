/* created   : 2020-05-30 17:21:11
 * accepted  : 2020-05-30 20:11:42
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>
#define square(x) (x) * (x)

const double INF = 1e10;

struct Node {
  int x, y, t;
  bool operator< (const Node& a) {
    return x < a.x;
  }
};

double dist(Node& a, Node& b) {
  if (a.t == b.t) {
    return INF;
  }
  return sqrt((ll) square(a.x - b.x) + (ll) square(a.y - b.y));
}

// t(n) = 2t(n/2) + O(n)
double rec(vector<Node>&a, int lo, int hi) {
  if (lo > hi) return INF;
  if (hi == lo) {
    return INF;
  }
  int md = lo + (hi - lo) / 2;
  double mi = min(rec(a, lo, md), rec(a, md + 1, hi));
  for (int i = md; i >= lo; i--) {
    if (a[md].x - a[i].x > mi) break;
    for (int j = md + 1; j <= hi; j++) {
      if (a[j].x - a[i].x > mi) break;
      mi = min(mi, dist(a[i], a[j]));
    }
  }
  return mi;
}

void solve() {
  int n; cin >> n;
  vector<Node> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].t = (i < n ? 0 : 1);
  }
  sort(all(a));
  cout << rec(a, 0, 2 * n - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(3);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
