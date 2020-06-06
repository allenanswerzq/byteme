/* created   : 2020-06-06 08:01:24
 * accepted  : 2020-06-06 09:07:00
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  list<int> li;
  unordered_map<int, decltype(li.begin())> mp;
  unordered_map<int, int> id;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    li.push_back(x);
    mp[i] = --li.end();
    id[x] = i;
  }
  trace(id);
  li.sort();
  vector<pair<int, int>> ans;
  for (int i = n - 1; i >= 1; i--) {
    auto it = mp[i];
    int mi = (1u << 31) - 1;
    int p = -1;
    auto hi = it;
    if (++hi != li.end()) {
      mi = min(mi, abs(*hi - *it));
      p = id[*hi];
    }
    auto lo = it;
    if (lo != li.begin()) {
      --lo;
      if (mi >= dbg(abs(*lo - *it))) {
        mi = abs(*lo - *it);
        p = id[*lo];
      }
    }
    trace(li, *hi, *lo, *it, mi, p);
    ans.push_back({mi, p});
    li.erase(it);
  }
  reverse(all(ans));
  for (auto t : ans) {
    cout << t.x << " " << t.y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
