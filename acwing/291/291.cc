/* created   : 2020-08-01 19:49:57
 * accepted  : 2020-08-01 20:02:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 2e6 + 7;
int a[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  trace(mt(a, 2 * n + 1));
  deque<int> qu;
  int len = n / 2;
  int ans = 0;
  for (int i = 1; i <= 2 * n; i++) {
    while (qu.size() && i - qu.front() > len) {
      qu.pop_front();
    }
    if (qu.size()) {
      ans = max(ans, i - qu.front() + a[qu.front()] + a[i]);
    }
    while (qu.size() && a[qu.back()] - qu.back() < a[i] - i) {
      qu.pop_back();
    }
    qu.push_back(i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
