/* created   : 2020-05-16 21:38:06
 * accepted  : 2020-05-16 23:00:44
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll a, b; cin >> a >> b;
  ll x = 0;
  while (x * (x + 1) <= (a + b) * 2) {
    x++;
  }
  x -= 1;
  assert(x >= 0);
  vector<int> ans(x + 1);
  for (ll i = x; i >= 1; i--) {
    // trace(i, a);
    if (a >= i) {
      a -= i;
      ans[i] = 1;
    }
    else {
      ans[a] = 1;
      a -= a;
      break;
    }
  }
  trace(x, a);
  vector<int> aa, bb;
  for (int i = 1; i <= x; i++) {
    if (ans[i]) {
      aa.push_back(i);
    }
    else {
      bb.push_back(i);
    }
  }
  int ca = aa.size();
  cout << ca << "\n";
  for (int i = 0; i < ca; i++) {
    cout << aa[i] << (i == ca - 1 ? "\n" : " ");
  }
  assert(x - ca == (int) bb.size());
  cout << x - ca << "\n";
  for (int i = 0; i < x - ca; i++) {
    cout << bb[i] << (i == x - ca - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
