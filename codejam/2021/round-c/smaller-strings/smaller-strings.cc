/* created   : 2021-05-29 10:12:04
 * accepted  : 2021-05-29 15:38:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

int add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

int mul(int a, int b) {
  return (int) ((ll) a * b % mod);
}

void solve() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  // abcde
  // abc
  // 012
  // adcb
  int n = (N + 1) / 2;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // ans = ans * K + (S[i] - 'a');
    ans = mul(ans, K);
    ans = add(ans, S[i] - 'a');
  }
  // abcaa
  // abcba
  string s = S.substr(n);
  string t = S.substr(0, N / 2);
  reverse(all(t));
  cout << add(ans, (t < s)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
