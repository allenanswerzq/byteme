/* created   : 2020-08-23 20:58:09
 * accepted  : 2020-08-26 10:11:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  // vector<int64_t> bit(N);
  // for (int i = 0; i < N; i++) {
  //   for (int a = i; a < N; a |= a+1) {
  //     bit[a] += E[i];
  //   }
  // }
  int N = 10;
  vector<int> bit(N);
  for (int i = 0; i < N; i++) {
    for (int a = i; a < N; a |= a+1) {
      trace(i, a, bitset<8>(a));
      bit[i] += i;
    }
  }
  // for (int a = cur; a > 0; a &= a-1) {
  //   cnd += bit[a-1];
  // }
  for (int i = 0; i < N; i++) {
    int t = 0;
    for (int a = i; a > 0; a &= a - 1) {
      trace(i, a - 1, bitset<8>(a));
      t += bit[a - 1];
    }
    trace(i, t);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
