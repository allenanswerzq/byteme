/* created   : 2020-02-28 21:49:19
 * accepted  : 2020-02-28 22:55:33
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
#endif
typedef long long ll;

const int N = 2e5 + 7;
vector<int> t1[N];
vector<int> t2[N];

vector<int> go(vector<int>* g, int n) {
  vector<int> ans(n);
  for (int u = 1; u < n; u++) {
    for (auto v : g[u]) {
      ans[v] = u;
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  n++;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  assert(a[0] == 1);
  int v = 2;
  for (int i = 1; i < n; i++) {
    if (a[i] > 1 && a[i - 1] > 1) {
      int tx = v - 1;
      int x = v;
      for (int j = 0; j < a[i]; j++) {
        t1[tx].push_back(x++);
      }
      int ty = v - 1;
      int y = v;
      for (int j = 0; j < a[i] - 1; j++) {
        t2[ty].push_back(y++);
      }
      t2[ty - 1].push_back(y++);
      assert(x == y);
      v = x;
    }
    else {
      int tx = v - 1;
      int x = v;
      for (int j = 0; j < a[i]; j++) {
        t1[tx].push_back(x++);
      }
      int ty = v - 1;
      int y = v;
      for (int j = 0; j < a[i]; j++) {
        t2[ty].push_back(y++);
      }
      assert(x == y);
      v = x;
    }
  }
  trace(v, mt(t1, v), mt(t2, v));
  vector<int> a1 = go(t1, v);
  vector<int> a2 = go(t2, v);
  if (a1 == a2) {
    cout << "perfect" << '\n';
    return;
  }
  cout << "ambiguous" << '\n';
  for (int i = 1; i < v; i++) {
    cout << a1[i] << (i == v - 1 ? '\n' : ' ');
  }
  for (int i = 1; i < v; i++) {
    cout << a2[i] << (i == v - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
