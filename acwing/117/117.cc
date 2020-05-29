/* created   : 2020-05-29 00:09:56
 * accepted  : 2020-05-29 00:48:02
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

struct Node {
  int parent;
  double avg;
  int sum;
  int size;
};

void solve() {
  int n, root; cin >> n >> root;
  vector<Node> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[i].sum = x;
    a[i].avg = x;
    a[i].size = 1;
    ans += a[i].sum;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    a[y].parent = x;
  }
  for (int i = 0; i < n - 1; i++) {
    double mx = 0;
    int who = -1;
    for (int j = 1; j <= n; j++) {
      if (j != root && a[j].avg > mx) {
        mx = a[j].avg;
        who = j;
      }
    }
    assert(who != -1);
    int par = a[who].parent;
    ans += a[par].size * a[who].sum;
    a[par].sum += a[who].sum;
    a[par].size += a[who].size;
    a[par].avg = a[par].sum * 1.0 / a[par].size;
    a[who].avg = -1;
    for (int j= 1; j <= n; j++) {
      if (a[j].parent == who) {
        a[j].parent = par;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
