/* created   : 2022-03-15 18:39:22
 * accepted  : 2022-03-15 21:24:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // greedy: all odd and even numbers should increasing
  int N; cin >> N;
  vector<ar> odd;
  vector<ar> even;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (x & 1) {
      odd.push_back({x, i});
    }
    else {
      even.push_back({x, i});
    }
  }
  sort(all(odd));
  sort(all(even));
  trace(odd);
  trace(even);
  for (int i = 0; i + 1 < odd.size(); i++) {
    if (odd[i][1] > odd[i + 1][1]) {
      cout << "No\n";
      return;
    }
  }
  for (int i = 0; i + 1 < even.size(); i++) {
    if (even[i][1] > even[i + 1][1]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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
