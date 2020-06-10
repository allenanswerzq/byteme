/* created   : 2020-06-09 08:46:58
 * accepted  : 2020-06-09 09:02:18
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

vector<int> merge(vector<int>& a, vector<int>& b) {
  priority_queue<pii, vector<pii>, greater<pii>> qu;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    qu.push({b[i] + a[0], 0});
  }
  vector<int> mi;
  for (int i = 0; i < n; i++) {
    int x = qu.top().x;
    int y = qu.top().y;
    qu.pop();
    mi.push_back(x);
    qu.push({x - a[y] + a[y + 1], y + 1});
  }
  return mi;
}

void solve() {
  int m, n; cin >> m >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  sort(all(a));
  for (int j = 0; j < m - 1; j++) {
    vector<int> b(n);
    for (auto& x : b) {
      cin >> x;
    }
    a = merge(a, b);
  }
  for (int j = 0; j < n; j++) {
    cout << a[j] << (j == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
