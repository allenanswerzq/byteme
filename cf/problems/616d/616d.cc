/* created   : 2020-05-13 23:27:31
 * accepted  : 2020-05-13 23:44:13
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  pair<int, int> best;
  int lo = 0;
  int hi = 0;
  while (hi < n) {
    if (lo > hi) {
      hi = lo;
    }
    while (hi < n) {
      mp[a[hi]]++;
      if ((int) mp.size() > k) {
        mp.erase(a[hi]);
        break;
      }
      hi++;
    }
    trace(lo, hi, mp);
    if (hi - lo > best.y - best.x) {
      best = {lo, hi};
    }
    if (--mp[a[lo]] == 0) {
      mp.erase(a[lo]);
    }
    lo++;
  }
  cout << best.x + 1 << " " << best.y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
