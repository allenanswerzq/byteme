/* created   : 2020-03-16 11:24:05
 * accepted  : 2020-03-16 12:43:47
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

struct Candy {
  int type = -1;
  int height = 0;
  int mass = 0;
  int idx = -1;
};

debugstream& operator<<(debugstream& os, const Candy& a) {
  return os << a.type << ' ' << a.height << ' ' << a.mass;
}

void solve() {
  int n, h; cin >> n >> h;
  vector<Candy> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].type >> a[i].height >> a[i].mass;
    a[i].idx = i;
  }
  // sort(all(a));
  trace(a);
  vector<Candy> best(2);
  for (int i = 0; i < n; i++) {
    if (a[i].type == 0 && h >= a[i].height) {
      if (a[i].mass > best[0].mass) {
        best[0] = a[i];
      }
    }
    if (a[i].type == 1 && h >= a[i].height) {
      if (a[i].mass > best[1].mass) {
        best[1] = a[i];
      }
    }
  }
  trace(best);
  int ans = 0;
  for (int t = 0; t < 2; t++) {
    if (best[t].type == -1) continue;
    int cur_h = h + best[t].mass;
    int cnt = 1;
    int last = t;
    vector<bool> use(n);
    use[best[t].idx] = true;
    while (1) {
      Candy mx;
      for (int i = 0; i < n; i++) {
        if (!use[i] && a[i].type != last && cur_h >= a[i].height) {
          if (a[i].mass > mx.mass) {
            mx = a[i];
          }
        }
      }
      trace(mx, cur_h, use);
      if (mx.idx == -1) {
        break;
      }
      cnt++;
      use[mx.idx] = true;
      last = mx.type;
      cur_h += mx.mass;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
