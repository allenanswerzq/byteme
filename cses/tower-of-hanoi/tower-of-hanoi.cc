/* created   : 2021-02-02 22:15:13
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<pair<int, int>> ans;

// move n disks from a --> c use b
int rec(int n, int a, int c, int b) {
  if (n == 0) return 0;
  // move n - 1 from a --> b use c
  int x = rec(n - 1, a, b, c);
  // move 1 from a --> c
  x += 1;
  ans.push_back({a, c});
  // move n - 1 from b --> c use a
  x += rec(n - 1, b, c, a);
  return x;
}

void solve() {
  int N; cin >> N;
  cout << rec(N, 1, 3, 2) << "\n";
  for (auto& t : ans) {
    cout << t.first << " " << t.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
}
