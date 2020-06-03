/* created   : 2020-06-02 23:05:06
 * accepted  : 2020-06-03 08:12:43
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n, cnt = 20;
vector<int> out;
vector<int> stk;
int inp = 1;

void dfs() {
  if (cnt == 0) {
    return;
  }
  if ((int) out.size() == n) {
    cnt--;
    for (int i = 0; i < n; i++) {
      cout << out[i];
    }
    cout << "\n";
    return;
  }
  if (stk.size()) {
    int x = stk.back();
    out.push_back(x);
    stk.pop_back();
    dfs();
    out.pop_back();
    stk.push_back(x);
  }
  if (inp <= n) {
    stk.push_back(inp);
    inp++;
    dfs();
    inp--;
    stk.pop_back();
  }
}

void solve() {
  cin >> n;
  dfs();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
