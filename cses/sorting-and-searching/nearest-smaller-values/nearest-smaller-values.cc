/* created   : 2020-11-08 21:40:46
 * accepted  : 2020-11-08 21:50:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  vector<int> stk;
  for (int i = 0; i < N; i++) {
    while (stk.size() && A[stk.back()] >= A[i]) {
      stk.pop_back();
    }
    if (i > 0) {
      cout << " ";
    }
    cout << (stk.empty() ? 0 : stk.back() + 1);
    stk.push_back(i);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
