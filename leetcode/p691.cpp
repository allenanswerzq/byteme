#include<bits/stdc++.h>
using namespace std;
// dp[i] denotes the mininum stickers needed for state `i`.
const int size = 1 << 15;
uint dp[size];
class Solution {
public:
  int minStickers(vector<string>& aa, string goal) {
    int n = sz(goal), m = 1 << n;
    mst(dp, -1);
    // par(dp, 15);
    // None of characters are matched with charactes in stickers.
    dp[0] = 0;
    fori (state, 0, m) {
      if (dp[state] == -1) continue;
      fora (strs, aa) {
        int cur = state;
        fora(c, strs)  {
          fori (k, 0, n)
          if (goal[k] == c && !(cur & (1 << k))) {
            cur |= 1 << k;
            break;
          }
        }
        dp[cur] = min(dp[cur], dp[state] + 1);
      }
    }
    return dp[m-1];
  }
};

void test(vs aa, string goal) {
  Solution go;
  int r = go.minStickers(aa, goal);
  output(r);
}

int main() {
  test({"with", "example", "science"}, "thehat");
  return 0;
}
