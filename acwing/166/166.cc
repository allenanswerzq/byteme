/* created   : 2020-06-21 11:35:23
 * accepted  : 2020-06-21 15:29:35
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
string str;

int lowbit(int x) { return x & -x; }

int get(int x, int y) {
  return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
  if (cnt == 0) return true;
  int mi = 10;
  int x = -1, y = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (str[i * N + j] == '.') {
        int cand_num = __builtin_popcount(get(i, j));
        if (cand_num < mi) {
          mi = cand_num;
          x = i, y = j;
        }
      }
    }
  }
  if (mi == 0) return false;
  assert(x != -1 && y != -1);
  for (int i = get(x, y); i > 0; i -= lowbit(i)) {
    int num = __builtin_ctz(i);
    row[x] ^= (1 << num);
    col[y] ^= (1 << num);
    cell[x / 3][y / 3] ^= (1 << num);
    str[x * N + y] = num + '1';
    if (dfs(cnt - 1)) return true;
    row[x] |= (1 << num);
    col[y] |= (1 << num);
    cell[x / 3][y / 3] |= (1 << num);
    str[x * N + y] = '.';
  }
  return false;
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
  for (int i = 0, k = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char ch = str[k++];
      if (ch != '.') {
        row[i] ^= 1 << (ch - '1');
        col[j] ^= 1 << (ch - '1');
        cell[i / 3][j / 3] ^= 1 << (ch - '1');
      }
      else {
        cnt++;
      }
    }
  }
  dfs(cnt);
  cout << str << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> str && str != "end") {
    solve();
  }
  return 0;
}
