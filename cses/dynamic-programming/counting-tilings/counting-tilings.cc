/* created   : 2021-02-21 15:33:31
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;
const int Z = 12;
int f[1001][1 << Z];
int vaild[1 << Z];

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve() {
  int N, M; cin >> N >> M;
  for (int st = 0; st < (1 << N); st++) {
    int zero = 0, odd = 0;
    for (int i = 0; i < N; i++) {
      if (st >> i & 1) {
        odd |= (zero & 1);
        zero = 0;
      }
      else {
        zero++;
      }
    }
    // 00100100
    vaild[st] = odd | (zero & 1) ? 0 : 1;
  }
  vector<vector<int>> cand(1 << N);
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < (1 << N); j++) {
      if ((i & j) == 0 && vaild[i | j]) {
        cand[i].push_back(j);
      }
    }
  }
  // i:    | |
  // i-1:  |_|(1)  [__](0)
  f[0][0] = 1;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      f[i][j] = 0;
      for (int k : cand[j]) {
        add(f[i][j], f[i - 1][k]);
      }
    }
  }
  cout << f[M][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
