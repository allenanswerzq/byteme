/* created   : 2021-09-20 16:18:23
 * accepted  : 2021-09-20 16:26:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int solution(vector<int>& A) {
  int N = A.size();
  vector<ar> B(N);
  for (int i = 0; i < N; i++) {
    B[i] = {A[i], i};
  }
  sort(all(B));
  int ans = 0;
  int cur = N;
  for (int i = N - 1; i >= 0; i--) {
    cur = min(cur, B[i][1]);
    if (cur == i) {
      ans++;
      cur = N;
    }
  }
  return ans;
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cout << solution(A) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
