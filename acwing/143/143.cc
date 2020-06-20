/* created   : 2020-06-20 10:14:53
 * accepted  : 2020-06-20 10:33:17
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
    while (k > 0 && !(pat[i] == pat[k])) {
      k = fail[k - 1];
    }
    if (pat[i] == pat[k]) {
      k++;
    }
    fail[i] = k;
  }
  return fail;
}

void solve(int n) {
  string s; cin >> s;
  vector<int> fail = fail_table(s);
  trace(s, fail);
  for (int i = 2; i <= n; i++) {
    int t = i - fail[i - 1];
    if (t < i && i % t == 0) {
      cout << i << " " << i / t << "\n";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int tc = 1;
  while (cin >> n && n) {
    cout << "Test case #" << tc++ << "\n";
    solve(n);
  }
  return 0;
}
