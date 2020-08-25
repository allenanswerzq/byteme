/* created   : 2020-08-24 11:17:44
 * accepted  : 2020-08-24 18:49:24
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, A, B, C; cin >> N >> A >> B >> C;
  if (A + B - C > N || (A + B - C == 1 && N >= 2)) {
    cout << "IMPOSSIBLE\n";
  }
  else if (N == 1) {
    cout << "1\n";
  }
  else if (N == 2) {
    if (C == 2) {
      cout << "1 1" << "\n";
    }
    else if (A == 2) {
      cout << "1 2" << "\n";
    }
    else if (B == 2) {
      cout << "2 1" << "\n";
    }
    else {
      assert(false);
    }
  }
  else {
    vector<int> ans;
    for (int i = 0; i < A - C; i++) {
      ans.push_back(2);
    }
    for (int i = 0; i < C; i++) {
      ans.push_back(3);
    }
    for (int i = 0; i < B - C; i++) {
      ans.push_back(2);
    }
    int extra = N - (A + B - C);
    if (extra) {
      ans.insert(ans.begin() + 1, extra, 1);
    }
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) cout << ' ';
      cout << ans[i];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
