/* created   : 2020-10-26 07:45:45
 * accepted  : 2020-10-26 08:05:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mp[x].push_back(i);
  }
  vector<int> ans;
  ll t = X;
  while (mp.size()) {
    vector<int> tmp;
    for (auto it = mp.begin(); it != mp.end(); ) {
      if (it->first > t) break;
      tmp.insert(tmp.end(), all(it->second));
      it = mp.erase(it);
    }
    t += X;
    // trace(t, mp);
    sort(all(tmp));
    ans.insert(ans.end(), all(tmp));
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
