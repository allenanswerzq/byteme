/* created   : 2020-07-03 19:07:44
 * accepted  : 2020-07-03 19:44:53
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int min_x = 0;
int sum = 0;
int n;

void dfs(int u, int last, int p, int s) {
  if (s > sum || (s == sum && p < min_x)) {
    sum = s;
    min_x = p;
  }
  for (int i = 1; i <= last; i++) {
    if ((ll) p * prime[u] > n) break;
    p = p * prime[u];
    dfs(u + 1, i, p, s * (i + 1));
  }
}

void solve() {
  cin >> n;
  dfs(0, 30, 1, 1);
  cout << min_x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
