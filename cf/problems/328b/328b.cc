/* created   : 2020-04-05 11:09:55
 * accepted  : 2020-04-05 11:17:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  string t; cin >> t;
  vector<int> have(10);
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '9') {
      t[i] = '6';
    }
    if (t[i] == '2') {
      t[i] = '5';
    }
    have[t[i] - '0']++;
  }
  vector<int> need(10);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '9') {
      s[i] = '6';
    }
    if (s[i] == '2') {
      s[i] = '5';
    }
    need[s[i] - '0']++;
  }
  int mi = 1e9;
  for (int i = 0; i < 10; i++) {
    if (have[i] > 0 && need[i] > 0) {
      mi = min(mi, have[i] / need[i]);
    }
  }
  cout << mi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
