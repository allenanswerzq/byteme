/* created   : 2020-06-26 15:27:17
 * accepted  : 2020-06-26 17:03:02
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// TODO(): TLE
vector<vector<int>> g;
vector<array<int, 3>> ans;
vector<int> cnt(12);
int n;

void move_to(int a, int b, int c) {
  swap(g[a][b], g[c][b]);
  while (1) {
    for (int x = 0; x < 5; x++) {
      int k = 0;
      for (int y = 0; y < 7; y++) {
        if (g[x][y]) {
          g[x][k++] = g[x][y];
        }
      }
      while (k < 7) {
        g[x][k++] = 0;
      }
    }
    // Looking for the blocks that we can remove.
    bool ok = false;
    vector<vector<bool>> need_remove(5, vector<bool>(7));
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 7; y++) {
        if (!g[x][y]) continue;
        {
          // horizontal check
          int lo = x, hi = x;
          while (lo - 1 >= 0 && g[lo - 1][y] == g[x][y]) lo--;
          while (hi + 1 < 5 && g[hi + 1][y] == g[x][y]) hi++;
          if (hi - lo + 1 >= 3) {
            ok = true;
            need_remove[x][y] = true;
          }
        }
        {
          // vertical check
          int lo = y, hi = y;
          while (lo - 1 >= 0 && g[x][lo - 1] == g[x][y]) lo--;
          while (hi + 1 < 7 && g[x][hi + 1] == g[x][y]) hi++;
          if (hi - lo + 1 >= 3) {
            ok = true;
            need_remove[x][y] = true;
          }
        }
      }
    }
    if (ok) {
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 7; y++) {
          if (need_remove[x][y]) {
            cnt[0]--;
            cnt[g[x][y]]--;
            g[x][y] = 0;
          }
        }
      }
    }
    else {
      break;
    }
  }
}

bool dfs(int u) {
  if (u == n) {
    return cnt[0] == 0;
  }
  for (int i = 1; i <= 10; i++) {
    if (cnt[i] == 1 || cnt[i] == 2) {
      return false;
    }
  }
  auto g_copy = g;
  auto cnt_copy = cnt;
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 7; y++) {
      if (g[x][y] == 0) continue;
      if (x + 1 < 5) {
        // Move this block to right.
        ans.push_back({x, y, 1});
        move_to(x, y, x + 1);
        if (dfs(u + 1)) return true;
        ans.pop_back();
        g = g_copy;
        cnt = cnt_copy;
      }
      if (x - 1 >= 0 && !g[x - 1][y]) {
        // Move this block to left.
        ans.push_back({x, y, -1});
        move_to(x, y, x - 1);
        if (dfs(u + 1)) return true;
        ans.pop_back();
        g = g_copy;
        cnt = cnt_copy;
      }
    }
  }
  return false;
}

void solve() {
  g.resize(5, vector<int>(7));
  cin >> n;
  for (int x = 0; x < 5; x++) {
    for (int y = 0, val = 0; cin >> val && val; y++) {
      cnt[0]++;
      cnt[val]++;
      g[x][y] = val;
    }
  }
  if (dfs(0)) {
    n = ans.size();
    for (int i = 0; i < n; i++) {
      cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }
  }
  else {
    cout << -1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
