/* created   : 2020-07-02 05:38:52
 * accepted  : 2020-07-02 20:00:20
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<bool> st(n + 1, true);
  st[0] = 0;
  st[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (st[i]) {
      for (int j = i + i; j <= n; j += i) {
        st[j] = false;
      }
    }
  }
  vector<int> prime;
  for (int i = 1; i <= n; i++) {
    if (st[i]) {
      prime.push_back(i);
    }
  }
  for (auto p : prime) {
    int cnt = 0;
    for (ll i = p; i <= n; i *= p) {
      cnt += n / i;
    }
    cout << p << " " << cnt << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
