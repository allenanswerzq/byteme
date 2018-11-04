#include<bits/stdc++.h>
using namespace std;

const int maxn = 60;
char aa[maxn][maxn];
int bb[maxn];
int solve() {
  int n, m; cin >> n >> m;
  mst(aa, 0);
  mst(bb, 0);
  fori (i, 1, n + 1) {
    string s; cin >> s;
    fori (j, 1, m + 1)
      aa[i][j] = s[j - 1];
  } 

  string s; cin >> s;
  fori (i, 1, m + 1)
    aa[0][i] = s[i - 1];

  fori (i, 1, n + 1)
    cin >> bb[i];

  if (n == 1) {
    int cnt = 0;
    fori (i, 1, m + 1) 
      cnt += aa[0][i] == aa[1][i];
    return m - abs(bb[1] - cnt);
  } else {
    int cnt[4] = {0, 0, 0, 0};
    // cnt[0]: the number of choices that neither friends agree with me
    // cnt[1]: the number of choices that the second friend agree with me
    // cnt[2]: the number of choices that the first friens agree with me
    // cnt[3]: the number of choices that both friends agree with me
    fori (i, 1, m + 1)
      ++cnt[(aa[0][i] == aa[1][i]) << 1 | (aa[0][i] == aa[2][i])];    

    int ans = 0;
    // If there are `i` choices are right in all the choices that neither
    // friends are agree with me. 
    fori (i, 0, cnt[0] + 1) 
      fori (j, 0, cnt[1] + 1) 
        fori (k, 0, cnt[2] + 1) 
          fori (l, 0, cnt[3] + 1) {
            if ((cnt[0] - i) + j + (cnt[2] - k) + l == bb[2] &&
                (cnt[0] - i) + (cnt[1] - j) + k + l == bb[1]) 
            ans = max(ans, i + j + k + l);
          }
    return ans;
  }
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    int r = solve();
    output(i, r); 
  } 

  return 0;
}
