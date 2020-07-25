/* created   : 2020-03-12 22:46:54
 * accepted  : 2020-03-13 08:46:09
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  ll a, b; cin >> a >> b;
  b = a - b;
  ll ans = a;
  for (int i = 0; i <= 18; i++){
    ll tail = 0;
    ll base = 1;
    for (int j = 0; j < i; j++){
      tail = tail * 10 + 9;
      base *= 10;
    }
    ll front = a / base;
    if (tail > a % base) {
      front--;
    }
    if (front < 0) continue;
    ll cur = front * base + tail;
    trace(front, tail, cur, ans);
    if (cur >= b){
      ans = cur;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
