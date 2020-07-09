/* created   : 2020-07-09 17:17:51
 * accepted  : 2020-07-09 19:38:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 1e3 + 7;
int phi[N];

void euler_phi() {
  for (int i = 2; i < N; i++) {
    phi[i] = i;
  }
  // x * (1 - 1 / a) * (1 - 1 / b) ...
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

void solve(int tc) {
  // gcd(x, y) == 1
  int n; cin >> n;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    // NOTE: phi[i] computes the lower half of the answer.
    ans += 2 * phi[i];
  }
  cout << tc << " " << n << " " << ans + 3 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  euler_phi();
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
