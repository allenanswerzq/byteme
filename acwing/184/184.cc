/* created   : 2020-06-26 09:12:11
 * accepted  : 2020-06-26 10:46:43
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

// abcd -> 0123
// badc 1032
// cbda 2130
//      d222
int n;
int mp[27];
char eq[3][30];
char seq[30];

bool check() {
  for (int j = n - 1, carry = 0; j >= 0; j--) {
    int a = eq[0][j] - 'A';
    int b = eq[1][j] - 'A';
    int c = eq[2][j] - 'A';
    if (mp[a] != -1 && mp[b] != -1 && mp[c] != -1) {
      a = mp[a], b = mp[b], c = mp[c];
      if (carry != -1) {
        if ((a + b + carry) % n != c) return false;
        // The most significant bit do not need to carry one.
        if (!j && a + b + carry >= n) return false;
        carry = (a + b + carry) / n;
      }
      else {
        if ((a + b + 0) % n != c && (a + b + 1) % n != c) return false;
        if (!j && a + b >= n) return false;
      }
    }
    else {
      carry = -1;
    }
  }
  return true;
}

bool dfs(int u, int state) {
  if (u == n) {
    return true;
  }
  for (int i = 0; i < n; i++) {
    if ((state & (1 << i)) == 0) {
      mp[seq[u] - 'A'] = i;
      if (check() && dfs(u + 1, state | (1 << i))) {
        return true;
      }
      mp[seq[u] - 'A'] = -1;
    }
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> eq[i];
  }
  vector<int> use(26);
  for (int j = n - 1, k = 0; j >= 0; j--) {
    for (int i = 0; i < 3; i++) {
      if (!use[eq[i][j] - 'A']) {
        use[eq[i][j] - 'A'] = true;
        seq[k++] = eq[i][j];
      }
    }
  }
  trace(seq);
  memset(mp, -1, sizeof(mp));
  dfs(0, 0);
  for (int i = 0; i < n; i++) {
    cout << mp[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
