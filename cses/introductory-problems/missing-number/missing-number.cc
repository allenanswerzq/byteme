/* created   : 2020-10-29 08:06:06
 * accepted  : 2020-10-29 08:10:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) {
    cin >> a;
    if (a > N || a < 1) {
      a = -1;
    }
  }
  for (int i = 0; i < N; i++) {
    while (A[i] != -1 && A[i] != i + 1) {
      swap(A[i], A[A[i] - 1]);
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i] == -1) {
      cout << i + 1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
