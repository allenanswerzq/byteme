/* created   : 2020-06-20 08:04:01
 * accepted  : 2020-06-20 08:18:29
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

string go(string& s) {
  int n = s.size();
  s += s;
  int i = 0, j = 1;
  while (i < n && j < n) {
    int k = 0;
    for (; k < n; k++) {
      if (s[i + k] != s[j + k]) {
        break;
      }
    }
    if (k == n) break;
    if (s[i + k] > s[j + k]) {
      i = i + k + 1;
      if (i == j) i++;
    }
    else {
      j = j + k + 1;
      if (i == j) j++;
    }
  }
  return s.substr(min(i, j), n);
}

void solve() {
  string a, b; cin >> a >> b;
  string aa = go(a);
  string bb = go(b);
  if (aa == bb) {
    cout << "Yes\n";
    cout << aa << "\n";
  }
  else {
    cout << "No\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
