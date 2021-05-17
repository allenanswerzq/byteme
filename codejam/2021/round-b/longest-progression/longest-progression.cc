/* created   : 2021-05-11 22:11:05
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int go(vector<int> & D) {
  int N = D.size();
  int ans = 0;
  for (int i = 0, j = 0; i < N; i = j) {
    while (j < N && D[i] == D[j])
      j++;
    ans = max(ans, j - i + 1);
    if (j < N) {
      // Fix only one number just right after this chunk
      // 0 0 0 0 2
      ans = max(ans, j - i + 2);
    }
    if (j < N && j + 1 < N && D[j] + D[j + 1] == 2 * D[i]) {
      // Try to fix two numbers right after this chunk
      // 0 0 0 -1 1
      int p = j + 2;
      while (p < N && D[p] == D[i])
        p++;
      ans = max(ans, p - i + 1);
    }
  }
  return ans;
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) {
    cin >> a;
  }
  vector<int> D(N - 1);
  for (int i = 0; i < N - 1; i++) {
    D[i] = A[i + 1] - A[i];
  }
  int ans = go(D);
  reverse(all(D));
  ans = max(ans, go(D));
  cout << ans << "\n";
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
