/* created   : 2020-06-08 22:06:06
 * accepted  : 2020-06-08 22:54:49
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void solve(int n) {
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].y >> a[i].x;
  }
  sort(all(a));
  trace(a);
  priority_queue<int, vector<int>, greater<int>> qu;
  for (int i = 0; i < n; i++) {
    int day = a[i].x;
    int price = a[i].y;
    qu.push(price);
    if ((int) qu.size() > day) {
      qu.pop();
    }
  }
  int ans = 0;
  while (qu.size()) {
    ans += qu.top();
    qu.pop();
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
