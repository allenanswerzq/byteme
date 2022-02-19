/* created   : 2021-08-28 17:42:19
 * accepted  : 2021-08-28 19:17:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // ____1??1______0??0____
  // 1?0, 0?1, 11, 00
  string S; cin >> S;
  vector<ar> seg;
  int lo = 0;
  int N = S.size();
  for (int i = 0; i < N; i++) {
    int c = 0;
    while (i < N && S[i] == '?') {
      c++, i++;
    }
    if (c == 0 && i > 0 && S[i - 1] == S[i]) {
      seg.push_back({i - lo, 0});
      lo = i;
    }
    else if (c > 0 && i < N && i - c - 1 >= 0) {
      if ((c % 2 == 0 && S[i] == S[i - c - 1]) ||
          (c % 2 == 1 && S[i] != S[i - c - 1])) {
        seg.push_back({i - lo, c});
        lo = i - c;
      }
    }
  }
  trace(lo);
  seg.push_back({S.size() - lo, 0});
  trace(seg);
  ll ans = 0;
  for (auto [c, e] : seg) {
    ans += c * 1ll * (c + 1) / 2;
    ans -= e * 1ll * (e + 1) / 2;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
