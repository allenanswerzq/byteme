/* created   : 2022-03-18 09:54:18
 * accepted  : 2022-03-18 13:02:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void add(int & a, int b) { a = ((ll)a + b) % MOD; }

int floor(int x) {
  // 2^k <= x < 2^(k+1)
  // 2^(k+1) + 1 <= 2x+1 < 2^(k+2) + 1
  int k = 0;
  while ((1u << k) <= x) {
    k++;
  }
  return k - 1;
}

void solve() {
  int N, P; cin >> N >> P;
  vector<int> A(N);
  set<int> st;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    st.insert(A[i]);
  }
  sort(all(A));
  for (int a : A) {
    int x = a;
    while (x > 0) {
      if (x & 1) {
        x >>= 1;
      }
      else if (x % 4 == 0) {
        x >>= 2;
      }
      else {
        break;
      }
      if (st.count(x)) {
        st.erase(a);
        break;
      }
    }
  }
  trace(st);
  vector<int> g(32);
  for (int a : st) {
    g[floor(a)]++;
  }
  // 110
  trace(g);
  // f[i]: the number of integers that the most signicant bit is at the `ith` position
  // f[i] = f[i-1] + f[i-2] + g(i)
  vector<int> f(P);
  for (int i = 0; i < P; i++) {
    if (i >= 1) add(f[i], f[i - 1]);
    if (i >= 2) add(f[i], f[i - 2]);
    if (i < 32) add(f[i], g[i]);
  }
  int ans = 0;
  for (int i = 0; i < P; i++) {
    add(ans, f[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
