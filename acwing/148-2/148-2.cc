/* created   : 2020-06-10 18:51:30
 * accepted  : 2020-06-10 19:15:49
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    st.insert(x);
  }
  if (st.size() == 1) {
    cout << 0 << "\n";
    return;
  }
  ll ans = 0;
  xuyixuyi();
  for (int i = 0; i < n - 1; i++) {
    int a = *st.begin(); st.erase(st.begin());
    int b = *st.begin(); st.erase(st.begin());
    ans += (a + b);
    st.insert(a + b);
  }
  xuyixuyi();
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
