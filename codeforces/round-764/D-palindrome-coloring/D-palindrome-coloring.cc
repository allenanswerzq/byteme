/* created   : 2022-01-10 23:41:23
 * accepted  : 2022-01-11 00:31:48
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  map<char, int> mp;
  string S; cin >> S;
  for (int i = 0; i < N; i++) {
    mp[S[i]]++;
  }
  trace(K, mp);
  vector<int> A;
  for (auto it : mp) {
    A.push_back(it.second);
  }
  vector<int> B;
  sort(all(A));
  // trace(A);
  for (int i = 0; i < A.size(); i++) {
    if (A[i] % 2) {
      B.push_back(1);
      A[i]--;
    }
  }
  trace(A, B);
  int s = 0;
  for (int i = 0; i < A.size(); i++) {
    s += A[i];
  }
  if (K > A.size()) {
    if (K >= s / 2) {
      cout << 2 << "\n";
    }
    else {
      cout << 2 + !B.empty() << "\n";
    }
    return;
  }
  cout << 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
