/* created   : 2020-06-20 10:40:10
 * accepted  : 2020-06-20 15:14:54
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<int> fail_table(const string& pat) {
  int n = pat.size();
  vector<int> fail(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && pat[i] != pat[k]) {
      k = fail[k - 1];
    }
    if (pat[i] == pat[k]) {
      k++;
    }
    fail[i] = k;
  }
  return fail;
}

void solve() {
  int n, m, q; cin >> n >> m >> q;
  string a, b; cin >> a >> b;
  vector<int> fail = fail_table(b);
  const int N = 2e5 + 7;
  vector<int> f(N);
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k > 0 && (k == m || a[i] != b[k])) {
      k = fail[k - 1];
    }
    if (a[i] == b[k]) {
      k++;
    }
    f[k]++;
  }
  // ......__i
  // ___   ___
  // trace(f, fail);
  for (int i = m; i > 0; i--) {
    f[fail[i - 1]] += f[i];
  }
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    cout << f[x] - f[x + 1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
