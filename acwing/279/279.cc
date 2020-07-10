/* created   : 2020-07-10 17:08:19
 * accepted  : 2020-07-10 17:22:01
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const ll mod = 2147483648;
const int N = 4e3 + 7;
int f[N];

void add(int& a, int b) { a = ((ll) a + b) % mod; }

void solve() {
  int n; cin >> n;
  f[0] = 1;
  // complete knapsack
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      add(f[j], f[j - i]);
    }
  }
  cout << f[n] - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
