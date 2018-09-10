#include<bits/stdc++.h>
using namespace std;

ll cnt[15][15][15][15];
ll comb[60][60];
ll height;

class ChristmasTree {
public:

  ll dp(int level, int r, int g, int b) {
    // Note:  returns 1 here.
    if (level == height + 1) return 1;

    ll ret = cnt[level][r][g][b];
    if (ret != -1) return ret;

    ll ans = 0;

    // Case 1: fill this level with only one color.
    if (r >= level) ans += dp(level+1, r-level, g, b);
    if (g >= level) ans += dp(level+1, r, g-level, b); 
    if (b >= level) ans += dp(level+1, r, g, b-level);

    // Case 2: fill this level with two colors.
    if (level % 2 == 0) {
      int k = level / 2;
      ll c = comb[level][k]; 
      if (r >=k && g >= k) ans += dp(level+1, r-k, g-k, b) * c;
      if (r >=k && b >= k) ans += dp(level+1, r-k, g, b-k) * c;
      if (g >=k && b >= k) ans += dp(level+1, r, g-k, b-k) * c;
    }

    // Case 3: fill this level with three colors.
    if (level % 3 == 0) {
      int k = level / 3;
      ll c = comb[level][k] * comb[level-k][k];
      if (r>=k && g>=k && b>=k) ans += dp(level+1, r-k, g-k, b-k) * c; 
    }

    cnt[level][r][g][b] = ans;

    return ans;
  }

  ll decorationWays(int h, int red, int green, int blue) {
    height = h;
    memset(cnt, -1, sizeof(cnt));

    // c(n, k) = c(n-1, k-1) + c(n-1, k)
    comb[0][0] = 1;
    fori(n, 0, 60)
      fori(k, 0, n+1)
        comb[n][k] = (k == 0) ? 1 : comb[n-1][k-1] + comb[n-1][k];

    return dp(1, red, green, blue);
  } 
  
};

// Expected:
// 1911899254684272

// Received:
// 1911898796777794

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  ChristmasTree go;
  cout << go.decorationWays(2, 1, 1, 1) << "\n";
  cout << go.decorationWays(8, 1, 15, 20) << "\n";
  // This case is wrong.
  cout << go.decorationWays(10, 50, 50, 50) << "\n";
  return 0;
}
