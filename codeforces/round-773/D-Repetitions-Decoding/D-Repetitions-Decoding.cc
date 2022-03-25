/* created   : 2022-03-25 20:22:01
 * accepted  : 2022-03-25 20:57:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 0   i
  // abcdabcddcb
  // a
  int N; cin >> N;
  vector<int> A(N);
  unordered_map<int, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }
  if (N & 1) {
    cout << -1 << "\n";
    return;
  }
  for (auto & it : mp) {
    if (it.second & 1) {
      cout << -1 << "\n";
      return;
    }
  }
  vector<int> seg;
  vector<ar> ops;
  int len = 0;
  while (A.size()) {
    int i = 1;
    while (A[i] != A[0]) i++;
    assert(i < A.size());
    // 0-----i---
    int c = 0;
    for (int j = 1; j < i; j++) {
      ops.push_back({len + i + j, A[j]});
      c++;
    }
    reverse(A.begin() + 1, A.begin() + i);
    A.erase(A.begin() + i);
    A.erase(A.begin());
    seg.push_back((c + 1) * 2);
    len += (c + 1) * 2;
  }
  cout << ops.size() << "\n";
  for (int i = 0; i < ops.size(); i++) {
    cout << ops[i][0] << " " << ops[i][1] << "\n";
  }
  cout << seg.size() << "\n";
  for (int i = 0; i < seg.size(); i++) {
    cout << seg[i] << (i == seg.size() - 1 ? '\n' : ' ');
  }
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
