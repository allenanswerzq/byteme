/* created   : 2020-05-04 20:39:02
 * accepted  : 2020-05-04 21:15:17
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

// void solve1() {
//   int n; cin >> n;
//   vector<int> a(n + 1);
//   for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//   }
//   vector<int> cnt(n + 1);
//   int cur = 1;
//   int ans = 0;
//   while (1) {
//     if (cur == n + 1) {
//       break;
//     }
//     ans++;
//     cnt[cur]++;
//     if (cnt[cur] % 2) {
//       cur = a[cur];
//     }
//     else {
//       cur++;
//     }
//   }
//   cout << ans << "\n";
// }

const int mod = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
}

int mul(int a, int b) {
  return (int) ((ll) a * b % mod);
}

const int N = 1e3 + 7;
int f[N];
int p[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    f[i + 1] = mul(2, f[i]);
    sub(f[i + 1], f[p[i]]);
    add(f[i + 1], 2);
  }
  cout << f[n + 1] % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
