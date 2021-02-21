/* created   : 2021-02-21 16:39:26
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void brute_force(int A, int B) {
  int cnt = 0;
  for (int i = A; i <= B; i++) {
    string s = to_string(i);
    bool ok = true;
    for (int j = 0; j + 1 < s.size(); j++) {
      if (s[j] == s[j + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cnt++;
      trace(i);
    }
  }
  trace(cnt);
}

void solve() {
  int A, B; cin >> A >> B;
  brute_force(1, 1212);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
