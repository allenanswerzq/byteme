/* created   : 2021-08-01 15:29:01
 * accepted  : 2021-08-01 15:54:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

bool check(vector<int>& a) {
  return a[0] + a[2] == 2 * a[1];
}

int diagonal(vector<vector<int>> & a) {
  int ans = 0;
  ans += (a[0][0] + a[2][2] == 2 * a[1][1]);
  ans += (a[2][0] + a[0][2] == 2 * a[1][1]);
  ans += (a[0][1] + a[2][1] == 2 * a[1][1]);
  ans += (a[1][0] + a[1][2] == 2 * a[1][1]);
  return ans;
}

void solve() {
  vector<vector<int>> A(3, vector<int>(3));
  vector<vector<int>> B(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      cin >> A[i][j];
      B[j][i] = A[i][j];
    }
  }
  trace(A);
  trace(B);
  int ans = 0;
  ans += check(A[0]);
  ans += check(A[2]);
  ans += check(B[0]);
  ans += check(B[2]);
  set<int> st;
  st.insert(ans);
  if ((A[0][0] + A[2][2]) % 2 == 0) {
    A[1][1] = (A[0][0] + A[2][2]) / 2;
    st.insert(ans + diagonal(A));
  }
  if ((A[0][2] + A[2][0]) % 2 == 0) {
    A[1][1] = (A[0][2] + A[2][0]) / 2;
    st.insert(ans + diagonal(A));
  }
  if ((A[0][1] + A[2][1]) % 2 == 0) {
    A[1][1] = (A[0][1] + A[2][1]) / 2;
    st.insert(ans + diagonal(A));
  }
  if ((A[1][0] + A[1][2]) % 2 == 0) {
    A[1][1] = (A[1][0] + A[1][2]) / 2;
    st.insert(ans + diagonal(A));
  }
  cout << *st.rbegin() << "\n";
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
