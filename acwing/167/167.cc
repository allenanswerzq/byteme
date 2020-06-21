/* created   : 2020-06-21 16:46:31
 * accepted  : 2020-06-21 17:44:11
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 65;
int stick[N];
int len;
int sum;
int n;

bool dfs(int u, int cur, int start, vector<int>& use) {
  if (u * len == sum) return true;
  if (cur == len) {
    return dfs(u + 1, 0, 0, use);
  }
  for (int i = start; i < n; i++) {
    if (use[i]) continue;
    int cand = stick[i];
    if (cur + cand > len) continue;
    use[i] = true;
    if (dfs(u, cur + cand, i + 1, use)) return true;
    use[i] = false;
    if (cur == 0) return false;
    if (cur + cand == len) return false;
    int j = i;
    while (j < n && stick[j] == stick[i]) j++;
    i = j - 1;
  }
  return false;
}

void solve() {
  sum = 0;
  len = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> stick[i];
    sum += stick[i];
    mx = max(mx, stick[i]);
  }
  trace(n, sum, mx);
  sort(stick, stick + n);
  reverse(stick, stick + n);
  vector<int> use(n);
  for (len = mx; len <= sum; len++) {
    if (sum % len) continue;
    if (dfs(0, 0, 0, use)) {
      cout << len << "\n";
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
