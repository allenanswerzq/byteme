/* created   : 2021-07-25 21:35:05
 * accepted  : 2021-07-25 21:38:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  set<int> st;
  for (int& a : A) {
    cin >> a;
    st.insert(a);
  }
  int M; cin >> M;
  vector<int> B(M);
  for (int& b : B) {
    cin >> b;
    st.insert(b);
  }
  for (int a : A) {
    for (int b : B) {
      if (!st.count(a + b)) {
        cout << a << " " << b << "\n";
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
