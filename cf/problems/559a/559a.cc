/* created   : 2020-04-06 10:22:03
 * accepted  : 2020-04-06 10:43:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int go(int x) {
  return x * x;
}

void solve() {
  vector<int> a(6);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  cout << go(a[0] + a[1] + a[2]) - go(a[0]) - go(a[2]) - go(a[4]) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
