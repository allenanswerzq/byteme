/* created   : 2020-05-10 11:04:01
 * accepted  : 2020-05-10 17:10:31
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<set<int>> a(n + 1);
  vector<int> cnt(n + 1);
  for (int i = 0; i < n - 2; i++) {
    int x, y, z; cin >> x >> y >> z;
    a[x].insert(y);
    a[x].insert(z);
    a[y].insert(x);
    a[y].insert(z);
    a[z].insert(x);
    a[z].insert(y);
    cnt[x]++;
    cnt[y]++;
    cnt[z]++;
  }
  vector<bool> use(n+ 1);
  int t1 = -1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1 && !use[i]) {
      use[i] = 1;
      t1 = i;
      break;
    }
  }
  int t2 = -1;
  for (auto x : a[t1]) {
    if (cnt[x] == 2 && !use[x]) {
      t2 = x;
      use[x] = 1;
      break;
    }
  }
  trace(t1, t2);
  vector<int> ans;
  ans.push_back(t1);
  ans.push_back(t2);
  for (int i = 3; i <= n; i++) {
    for (auto x : a[t1]) {
      if (!use[x]) {
        t1 = t2;
        t2 = x;
        use[x] = 1;
        ans.push_back(x);
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
