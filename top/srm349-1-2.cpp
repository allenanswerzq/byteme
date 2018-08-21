#include<bits/stdc++.h>
using namespace std;

        cout << "\n"; } cout << "\n"
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Denotes number of different formations of the first i dice, with the last 
// dice equal to j. 

// Note: number type.
// int dp[40][40];
ll dp[40][40];

class DiceGames
{
public:
  ll countFormations(vi sides) {
    int n = sz(sides);
    memset(dp, 0, sizeof(dp));

    sort(all(sides));

    fori(i, 0, sides[0])
      dp[0][i] = 1;

    fori(i, 1, n) {
      fori(j, 0, sides[i]) {
        fori(k, 0, j+1)
          dp[i][j] += dp[i-1][k];
      }
    }

    ll ret = 0;
    fori(i, 0, sides[n-1])
      ret += dp[n-1][i];
    return ret;
  } 
};

// Expected:
// 916312070471295267

// Received:
// -3626491613

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  DiceGames go;
  cout << go.countFormations({4}) << "\n";
  cout << go.countFormations({2, 2}) << "\n";
  cout << go.countFormations({4, 4}) << "\n";
  cout << go.countFormations({3, 4}) << "\n";
  cout << go.countFormations({4, 5, 6}) << "\n";
  vi a = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 
          32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
  cout << go.countFormations(a) << "\n";
  return 0;
}
