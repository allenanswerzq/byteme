/* created   : 2020-05-12 23:27:35
 * accepted  : 2020-05-12 23:55:07
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int k; cin >> k;
  if (k == 0) {
    cout << "a" << "\n";
    return;
  }
  k *= 2;
  string ans;
  char ch = 'a';
  while (k > 0) {
    int x = 1;
    while ((x + 1) * x <= k) {
      x++;
    }
    k -= x * (x - 1);
    trace(k, x);
    ans += string(x, ch++);
  }
  assert(k == 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
