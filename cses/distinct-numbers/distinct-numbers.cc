/* created   : 2020-11-03 08:07:04
 * accepted  : 2020-11-03 08:09:48
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  set<int> st;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    st.insert(x);
  }
  cout << st.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
