/* created   : 2021-05-30 11:11:10
 * accepted  : 2021-05-30 18:05:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

const int Z = 62;
pair<double, int> f[Z][Z][Z];

void solve() {
  int W, E; cin >> W >> E;
  trace(W, E);
  const int N = 60;
  // Compute the maxinum expected value for a game in 60 rounds
  for (int a = N; a >= 0; a--) {
    for (int b = N - a; b >= 0; b--) {
      for (int c = N - a - b; c >= 0; c--) {
        f[a][b][c] = {0, -1};
        // Compute the probility for my firend
        double prob_a = 1.0 / 3;
        double prob_b = 1.0 / 3;
        double prob_c = 1.0 / 3;
        // a > b > c > a
        if (a + b + c != 0) {
          prob_a = b * 1.0 / (a + b + c);
          prob_b = c * 1.0 / (a + b + c);
          prob_c = a * 1.0 / (a + b + c);
        }
        // Me chose to play `a`, the friend also plays `a` then tie, plays b I win
        double exp_a = f[a + 1][b][c].first + prob_a * E + prob_b * W;
        f[a][b][c] = max(f[a][b][c], {exp_a, 0});
        // Me chose to play `b`
        double exp_b = f[a][b + 1][c].first + prob_b * E + prob_c * W;
        f[a][b][c] = max(f[a][b][c], {exp_b, 1});
        // Me chose to play `c`
        double exp_c = f[a][b][c + 1].first + prob_c * E + prob_a * W;
        f[a][b][c] = max(f[a][b][c], {exp_c, 2});
      }
    }
  }
  trace(f[0][0][0]);
  // Find the maxinum path
  // Go back from the final state to the begin state
  int a = 0, b = 0, c = 0;
  while (a + b + c != N) {
    int m = f[a][b][c].second;
    if (m == 0) {
      a++;
    }
    else if (m == 1) {
      b++;
    }
    else {
      c++;
    }
    string s = "RSP";
    cout << s[m];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  int X; cin >> X;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
