/* created   : 2020-11-01 21:14:22
 * accepted  : 2020-11-01 21:20:16
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  string S; cin >> S;
  vector<int> cnt(26);
  for (char c : S) {
    cnt[c - 'A']++;
  }
  int odd = 0;
  string a, b;
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      int c = cnt[i] / 2;
      odd += (cnt[i] & 1);
      if (odd > 1) {
        cout << "NO SOLUTION\n";
        return;
      }
      a += string(c, 'A' + i);
      b += string(c, 'A' + i);
      cnt[i] -= 2 * c;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 0) {
      a += string(1, 'A' + i);
    }
  }
  reverse(all(b));
  cout << a + b << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
