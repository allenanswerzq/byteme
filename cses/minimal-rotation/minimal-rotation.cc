/* created   : 2021-01-01 20:21:14
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int lexicographically_minimal_string(const string& s) {
  int n = (int) s.size();
  int i = 0, j = 1, k = 0;
  while (k < n && i < n && j < n) {
    char a = s[(i + k) % n];
    char b = s[(j + k) % n];
    if (a == b) {
      k++;
    }
    else if (a > b) {
      i = i + k + 1;
      k = 0;
      if (i == j) i++;
    }
    else {
      j = j + k + 1;
      k = 0;
      if (i == j) i++;
    }
  }
  return min(i, j);
}

void solve() {
  string S; cin >> S;
  int p = lexicographically_minimal_string(S);
  cout << S.substr(p) + S.substr(0, p) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
