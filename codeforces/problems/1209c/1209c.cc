/* created   : 2020-04-30 22:19:41
 * accepted  : 2020-04-30 23:36:41
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  bool find = false;
  for (char ch = '0'; ch <= '9'; ch++) {
    vector<int> ans(n);
    bool big = false;
    for (int i = 0; i < n; i++) {
      if (s[i] < ch) {
        ans[i] = 1;
      }
      else if (s[i] > ch) {
        big = true;
        ans[i] = 2;
      }
      else {
        if (big) {
          ans[i] = 1;
        }
        else {
          ans[i] = 2;
        }
      }
    }
    string str;
    for (int i = 0; i < n; i++) {
      if (ans[i] == 1) {
        str += s[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans[i] == 2) {
        str += s[i];
      }
    }
    bool ok = true;
    for (int i = 0; i + 1 < n; i++) {
      if (str[i] > str[i + 1]) {
        ok = false;
        break;
      }
    }
    // trace(ch, str, ans, ok);
    if (ok) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "\n" : "");
      }
      find = true;
      break;
    }
  }
  if (!find) {
    cout << "-" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
