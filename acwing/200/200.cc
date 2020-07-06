/* created   : 2020-07-06 08:20:08
 * accepted  : 2020-07-06 09:08:05
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
vector<int> get_prime() {
  vector<int> prime;
  bitset<N> bs;
  bs.set();
  bs[0] = 0;
  bs[1] = 0;
  for (int i = 2; i < N; i++) {
    if (bs.test(i)) {
      for (int j = i + i; j < N; j += i) {
        bs.reset(j);
      }
      prime.push_back(i);
    }
  }
  return prime;
}

const int N = 5e4;
pair<int, int> factor[52];
vector<int> prime;
int divs[N];
int cntd;
int cntf;

// find all the dividers
void dfs(int u, int p) {
  if (u >= cntf) {
    divs[cntd++] = p;
    return;
  }
  for (int i = 0; (int) i <= factor[u].y; i++) {
    dfs(u + 1, p);
    p *= factor[u].x;
  }
}

void solve() {
  int a0, a1, b0, b1;
  cin >> a0 >> a1 >> b0 >> b1;
  // sqrt(b1)
  int d = b1;
  cntf = 0;
  for (int i = 0; prime[i] <= d / prime[i]; i++) {
    int p = prime[i];
    int s = 0;
    while (d % p == 0) {
      d /= p;
      s++;
    }
    if (s > 0) {
      factor[cntf++] = {p, s};
    }
  }
  if (d > 1) {
    factor[cntf++] = {d, 1};
  }
  // logb1
  cntd = 0;
  dfs(0, 1);
  trace(mt(factor, 10), mt(divs, 20));
  int ans = 0;
  for (int i = 0; i < cntd; i++) {
    int x = divs[i];
    if (__gcd(a0, x) == a1 && (ll) x * b0 / __gcd(x, b0) == b1) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  prime = get_prime<N>();
  while (tc--) {
    solve();
  }
  return 0;
}
