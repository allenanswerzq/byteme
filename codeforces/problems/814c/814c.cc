/* created   : 2020-05-16 16:22:06
 * accepted  : 2020-05-16 20:37:03
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void amax(int& a, int b) { a = max(a, b); }

const int N = 1523;
int f[N][27];
int t[N][27];
int g[N][27];

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 1; i <= n; i++) {
    for (int cnt = 0; cnt <= n; cnt++) {
      for (int ch = 0; ch < 26; ch++) {
        if (ch == s[i - 1] - 'a') {
          f[cnt][ch] = 1;
          amax(f[cnt][ch], t[cnt][ch] + 1);
          amax(g[cnt][ch], f[cnt][ch]);
        }
        else {
          f[cnt][ch] = 0;
          if (cnt >= 1) {
            amax(f[cnt][ch], t[cnt - 1][ch] + 1);
            amax(g[cnt][ch], f[cnt][ch]);
          }
        }
      }
    }
    memcpy(t, f, sizeof(t));
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int cnt; char ch; cin >> cnt >> ch;
    cout << g[cnt][ch - 'a'] << "\n";
  }
}

// const int N = 1523;
// int f[N][27];
// int ps[N][27];

// void solve() {
//   int n; cin >> n;
//   string s; cin >> s;
//   for (int i = 0; i < n; i++) {
//     for (int k = 0; k < 26; k++) {
//       ps[i + 1][k] = ps[i][k] + (s[i] - 'a' == k);
//     }
//   }
//   for (int i = 0; i < n; i++) {
//     for (int j = i; j < n; j++) {
//       for (int k = 0; k < 26; k++) {
//         int c = ps[j + 1][k] - ps[i][k];
//         amax(f[j - i + 1 - c][k], j - i + 1);
//       }
//     }
//   }
//   for (int cnt = 0; cnt + 1 < N; cnt++) {
//     for (int k = 0; k < 26; k++) {
//       amax(f[cnt + 1][k], f[cnt][k]);
//     }
//   }
//   int q; cin >> q;
//   for (int i = 0; i < q; i++) {
//     int cnt; char ch; cin >> cnt >> ch;
//     cout << f[cnt][ch - 'a'] << "\n";
//   }
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
