/* created   : 2022-02-23 22:34:04
 * accepted  : 2022-02-24 00:12:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 1 x x x 1 x 3 4 x x x 4 7
  // |-------|
  //   |---|
  //     |-------|
  //               |-------|
  // 5 + 2 - 3 = 4
  int N; cin >> N;
  unordered_map<int, int> mi;
  unordered_map<int, int> mx;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mi[x] = min(mi.count(x) ? mi[x] : N, i);
    mx[x] = max(mx.count(x) ? mx[x] : 0, i);
    A[i] = x;
  }
  trace(A);
  vector<ar> pos;
  unordered_set<int> was;
  for (int i = 0; i < N; i++) {
    int x = A[i];
    if (!was.count(x)) {
      was.insert(x);
      pos.push_back({mi[x], mx[x]});
    }
  }
  sort(all(A));
  vector<ar> dup;
  int M = pos.size();
  for (int i = 0; i < M; ) {
    dup.push_back(pos[i]);
    int j = i + 1;
    while (j < M && pos[i][0] <= pos[j][0] && pos[j][1] <= pos[i][1]) {
      j++;
    }
    i = j;
  }
  trace(dup);
  M = dup.size();
  int ans = 0;
  for (int i = 0; i < M; i++) {
    // |-------| i
    //      |--------|
    //           |-----------| j
    int j = i;
    while (j + 1 < M && dup[j][0] <= dup[j + 1][0] && dup[j + 1][0] <= dup[j][1]) {
      j++;
    }
    int len = dup[j][1] - dup[i][0] + 1 - 2 - (j - i);
    if (len > 0) {
      ans += len;
    }
    i = j;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
