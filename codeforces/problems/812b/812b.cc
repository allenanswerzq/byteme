/* created   : 2020-09-04 07:45:50
 * accepted  : 2020-09-06 09:07:22
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void amin(int& a, int b) { a = min(a, b); }

const int NX = 20;
int f[NX][2];
vector<string> A;
int N, M;

int rec(int x, int y) {
  int& ans = f[x][y];
  if (ans >= 0) return ans;
  bool ok = true;
  for (int i = x + 1; i < N; i++) {
    if (A[i] != string(M, '0')) {
      ok = false;
      break;
    }
  }
  if (ok) {
    // If after accessing row x, we are done.
    if (y == 0) {
      // we are at the left upstairs.
      int i = M - 1;
      while (i >= 0 && A[x][i] == '0') i--;
      ans = max(i, 0);
    }
    else {
      int i = 0;
      while (i < M && A[x][i] == '0') i++;
      ans = max(M - 1 - i, 0);
    }
    return ans;
  }
  ans = 1e9;
  // 1). go to the other side upstairs, and go up to the next floor
  amin(ans, rec(x + 1, y ^ 1) + M);
  if (y == 0) {
  // 2). current at left side, also go up to next level from this side.
    int i = M - 1;
    while (i > 0 && A[x][i] == '0') i--;
    amin(ans, 2 * i + 1 + rec(x + 1, y));
  }
  else {
  // 3). current at right side, also go up to next level from this side.
    int i = 0;
    while (i < M - 1 && A[x][i] == '0') i++;
    amin(ans, 2 * (M - 1 - i) + 1 + rec(x + 1, y));
  }
  return ans;
}

void solve() {
  cin >> N >> M;
  M += 2;
  A.resize(N);
  for (auto& s : A) {
    cin >> s;
  }
  reverse(all(A));
  memset(f, 0xff, sizeof(f));
  trace(f[0][0]);
  cout << rec(0, 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
