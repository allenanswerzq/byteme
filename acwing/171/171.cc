/* created   : 2020-06-23 08:27:58
 * accepted  : 2020-06-23 12:43:51
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 50;
int n, max_weight;
int bag[N];
ll mx;

void dfs(int u, ll cur, vector<ll>& ans) {
  if (cur > max_weight) return;
  if (u > n / 2) {
    ans.push_back(cur);
    return;
  }
  dfs(u + 1, cur, ans);
  if (cur + bag[u] < max_weight) {
    dfs(u + 1, cur + bag[u], ans);
  }
}

void dfs2(int u, ll cur, vector<ll>& ans) {
  if (cur > max_weight) return;
  if (u > n - 1) {
    auto it = upper_bound(all(ans), max_weight - cur);
    if (it != ans.begin()) {
      mx = max(mx, cur + *(--it));
    }
    return;
  }
  dfs2(u + 1, cur, ans);
  if (cur + bag[u] < max_weight) {
    dfs2(u + 1, cur + bag[u], ans);
  }
}

void solve() {
  cin >> max_weight >> n;
  for (int i = 0; i < n; i++) {
    cin >> bag[i];
  }
  sort(bag, bag + n);
  reverse(bag, bag + n);
  vector<ll> path;
  dfs(0, 0, path);
  sort(all(path));
  path.erase(unique(all(path)), path.end());
  dfs2(n / 2 + 1, 0, path);
  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
