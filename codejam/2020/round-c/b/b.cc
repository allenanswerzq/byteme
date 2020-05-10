/* created   : 2020-05-02 17:42:25
 * accepted  : 2020-05-02 17:59:43
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int u; cin >> u;
  int n = 1e4;
  vector<pair<int, string>> a(n);
  set<char> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    for (auto c : a[i].y) {
      st.insert(c);
    }
  }
  assert(st.size() == 10);
  string v(all(st));
  auto get = [&](string& ss) {
    vector<int> mp(26);
    for (int i = 0; i < (int) v.size(); i++) {
      mp[v[i] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 0; i < (int) ss.size(); i++) {
      int d = mp[ss[i] - 'A'];
      ans = ans * 10 + d;
    }
    return ans;
  };
  // trace(st, v);
  int cnt = 0;
  do {
    // if (++cnt > 2) {
    //   break;
    // }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      // trace(v, a[i]);
      if (a[i].x < (get(a[i].y))) {
        ok = false;
        break;
      }
    }
    // trace(v, ok);
    if (ok) {
      cout << v << "\n";
      return;
    }
  } while (next_permutation(all(v)));
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
