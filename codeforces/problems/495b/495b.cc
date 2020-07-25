/* created   : 2020-05-10 23:37:40
 * accepted  : 2020-05-10 23:44:21
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int a, b; cin >> a >> b;
  if (a - b == 0) {
    cout << "infinity\n";
    return;
  }
  int x = abs(a - b);
  set<int> st;
  for (int k = 1; k * k <= a; k++) {
    if (x % k == 0) {
      if (a % k == b) {
        st.insert(k);
      }
      if (a % (x / k) == b) {
        st.insert(x / k);
      }
    }
  }
  trace(a, st);
  cout << st.size() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
