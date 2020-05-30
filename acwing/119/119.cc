/* created   : 2020-05-30 15:39:38
 * accepted  : 2020-05-30 16:38:37
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int get(char ch) {
  if (ch == 'A') {
    return 1;
  }
  else if (ch == 'J') {
    return 11;
  }
  else if (ch == 'Q') {
    return 12;
  }
  else if (ch == 'K') {
    return 13;
  }
  else if (ch == '0') {
    return 10;
  }
  else {
    return ch - '0';
  }
}

void solve() {
  vector<vector<int>> a(14);
  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      char ch; cin >> ch;
      a[i].push_back(get(ch));
    }
  }
  trace(a);
  vector<int> open(14);
  for (int i = 0; i < 4; i++) {
    int t = a[13][i];
    while (t != 13) {
      open[t]++;
      int r = a[t].back();
      a[t].pop_back();
      t = r;
    }
  }
  int ans = 0;
  for (int i = 0; i <= 12; i++) {
    ans += open[i] >= 4;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
