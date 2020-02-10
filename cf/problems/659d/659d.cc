/* created   : 2020-02-09 15:25:26
 * accepted  : 2020-02-09 16:17:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

int check(string t){
  if (t == "UL") return 1;
  if (t == "UR") return 0;
  if (t == "DL") return 0;
  if (t == "DR") return 1;
  if (t == "LU") return 0;
  if (t == "LD") return 1;
  if (t == "RU") return 1;
  if (t == "RD") return 0;
  assert(0);
}

void solve() {
  int n; cin >> n;
  vector<int> x(n + 1);
  vector<int> y(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  string s;
  for (int i = 0; i < n; i++) {
    if (x[i] < x[i + 1]) s += 'R';
    if (x[i] > x[i + 1]) s += 'L';
    if (y[i] < y[i + 1]) s += 'U';
    if (y[i] > y[i + 1]) s += 'D';
  }
  trace(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string t;
    t += s[i];
    t += s[(i + 1) % n];
    ans += check(t);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
