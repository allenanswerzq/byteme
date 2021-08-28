/* created   : 2021-08-28 15:56:30
 * accepted  : 2021-08-28 17:30:14
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> even;
  vector<int> odd;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (x & 1) {
      odd.push_back(x);
    }
    else {
      even.push_back(x);
    }
  }
  even.insert(even.end(), all(odd));
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (__gcd(even[j], 2 * even[i]) > 1) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
