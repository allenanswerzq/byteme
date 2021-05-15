/* created   : 2020-11-12 10:07:06
 * accepted  : 2020-11-12 11:56:51
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> ps(N + 1);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    ps[i + 1] = ps[i] + x;
  }
  //        [-----B---------]
  //                 [---A--]
  //  ------j--------k------i
  multiset<ll> st;
  ll ans = -2e18;
  for (int i = A - 1; i < N; i++) {
    st.insert(ps[i - A + 1]);
    ans = max(ans, ps[i + 1] - *st.begin());
    trace(i, st, A, B);
    if (i >= B - 1) {
      st.erase(st.find(ps[i - B + 1]));
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
