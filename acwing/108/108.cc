/* created   : 2020-05-24 17:00:26
 * accepted  : 2020-05-24 21:26:01
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int id, m; cin >> id >> m;
  priority_queue<int, vector<int>> mx;
  priority_queue<int, vector<int>, greater<int>> mi;
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    mi.push(x);
    if (mx.size() && mi.top() < mx.top()) {
      int a = mi.top(); mi.pop();
      int b = mx.top(); mx.pop();
      mi.push(b);
      mx.push(a);
    }
    if (mi.size() > mx.size() + 1) {
      mx.push(mi.top());
      mi.pop();
    }
    if (!(i & 1)) {
      ans.push_back(mi.top());
    }
  }
  m = ans.size();
  cout << id << " " << m << "\n";
  for (int i = 0; i < m; i++) {
    if (i && i % 10 == 0) {
      cout << "\n";
    }
    else if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();  }
  return 0;
}
