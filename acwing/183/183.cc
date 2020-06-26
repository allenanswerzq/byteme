/* created   : 2020-06-25 21:22:50
 * accepted  : 2020-06-25 21:52:45
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 9;
int row[N];
int col[N];
int cell[N][N];
int a[N][N];
int ans;

int lowbit(int x) { return x & -x; }

int get(int x, int y) {
  return row[x] & col[y] & cell[x / 3][y / 3];
}

int get_score(int x, int y) {
  return min({x, 8 - x, y, 8 - y}) + 6;
}

void dfs(int cnt, int score) {
  if (cnt == 0) {
    ans = max(ans, score);
    return;
  }
  int mi = 10;
  int x = -1, y = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] == 0) {
        int cand_num = __builtin_popcount(get(i, j));
        if (cand_num < mi) {
          mi = cand_num;
          x = i, y = j;
        }
      }
    }
  }
  // No candiate values to choose.
  // trace(x, y, mi, get(x, y));
  if (mi == 0) return;
  assert(x != -1 && y != -1);
  for (int i = get(x, y); i > 0; i -= lowbit(i)) {
    int num = __builtin_ctz(i);
    row[x] -= (1 << num);
    col[y] -= (1 << num);
    cell[x / 3][y / 3] -= (1 << num);
    a[x][y] = num + 1;
    dfs(cnt - 1, score + get_score(x, y) * (num + 1));
    row[x] += (1 << num);
    col[y] += (1 << num);
    cell[x / 3][y / 3] += (1 << num);
    a[x][y] = 0;
  }
  return;
}

void solve() {
  for (int i = 0; i < N; i++) {
    row[i] = (1 << N) - 1;
    col[i] = (1 << N) - 1;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cell[i][j] = (1 << N) - 1;
    }
  }
  int cnt = 0;
  int score = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x; cin >> x;
      a[i][j] = x;
      if (x > 0) {
        row[i] -= 1 << (x - 1);
        col[j] -= 1 << (x - 1);
        cell[i / 3][j / 3] -= 1 << (x - 1);
        score += get_score(i, j) * x;
      }
      else {
        cnt++;
      }
    }
  }
  ans = -1;
  dfs(cnt, score);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
