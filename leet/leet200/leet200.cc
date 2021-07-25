/* created   : 2020-10-19 21:51:10
 * accepted  : 2020-10-19 21:58:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int numIslands(vector<vector<char>>& A) {
    if (A.empty()) return 0;
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (A[i][j] == '1') {
          ans++;
          vector<pair<int, int>> stk;
          stk.push_back(make_pair(i, j));
          while (stk.size()) {
            int x = stk.back().first;
            int y = stk.back().second;
            A[x][y] = 'X';
            stk.pop_back();
            for (int k = 0; k < 4; k++) {
              int nx = x + vector<int>({0, 0, -1, 1})[k];
              int ny = y + vector<int>({-1, 1, 0, 0})[k];
              if (size_t(nx) < n && size_t(ny) < m && A[nx][ny] == '1') {
                stk.push_back(make_pair(nx, ny));
              }
            }
          }
        }
      }
    }
    return ans;
  }
};

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
