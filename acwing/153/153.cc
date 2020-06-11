/* created   : 2020-06-11 18:30:31
 * accepted  : 2020-06-11 20:01:41
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 1100;
vector<int> g[N];
int color[N];

void dfs(int u, int col) {
  color[u] = col;
  for (auto v : g[u]) {
    if (color[v] == col) {
      cout << 0 << "\n";
      exit(0);
    }
    if (color[v] == -1) {
      dfs(v, 1 - col);
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> f(n + 1);
  f[n] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    f[i] = min(f[i + 1], a[i]);
  }
  trace(f);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // i < j < k, a[k] < a[i] < a[j]
      if (f[j] < a[i] && a[i] < a[j]) {
        trace(i, j);
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  memset(color, -1, sizeof(color));
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      dfs(i, 0);
    }
  }
  trace(mt(color, n));
  vector<int> stk1, stk2;
  int now = 1;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      while (stk1.size() && stk1.back() == now) {
        stk1.pop_back();
        cout << "b ";
        now++;
      }
      stk1.push_back(a[i]);
      cout << "a ";
    }
    else {
      while (true) {
        if (stk1.size() && stk1.back() == now) {
          stk1.pop_back();
          cout << "b ";
          now++;
        }
        else if (stk2.size() && stk2.back() == now) {
          stk2.pop_back();
          cout << "d ";
          now++;
        }
        else {
          break;
        }
      }
      stk2.push_back(a[i]);
      cout << "c ";
    }
  }
  while (true) {
    if (stk1.size() && stk1.back() == now) {
      stk1.pop_back();
      cout << "b ";
      now++;
    }
    else if (stk2.size() && stk2.back() == now) {
      stk2.pop_back();
      cout << "d ";
      now++;
    }
    else {
      break;
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
