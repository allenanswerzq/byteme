/* created   : 2020-05-03 11:45:41
 * accepted  : 2020-05-03 20:07:57
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, k, s; cin >> n >> k >> s;
  if (k > s || (n - 1) * k < s) {
    cout << "NO\n";
    return;
  }
  int t = s / k;
  int r = s % k;
  int cur = 1;
  ll sum = 0;
  cout << "YES" << "\n";
  for (int i = 0; i < k; i++) {
    int step = t + (i < r);
    sum += step;
    if (i % 2 == 0) {
      cur += step;
    }
    else {
      cur -= step;
    }
    cout << cur << (i == k - 1 ? "\n" : " ");
  }
  assert(sum == s);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
