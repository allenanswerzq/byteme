/* created   : 2020-03-30 21:25:30
 * accepted  : 2020-03-30 21:43:57
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  map<int, pair<int, int>> mp;
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int p = s.find('+');
    assert(p != -1);
    int x = stoi(s.substr(1, p - 1));
    int q = s.find('/');
    assert(q != -1);
    assert(q - p - 2 > 0);
    int y = stoi(s.substr(p + 1, q - p - 2));
    int z = stoi(s.substr(q + 1));
    int g = __gcd(x + y, z);
    // trace(x, y, z, ans);
    cnt[{(x + y) / g, z / g}]++;
    mp[i] = {(x + y) / g, z / g};
  }
  for (int i = 0; i < n; i++) {
    cout << cnt[mp[i]] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
