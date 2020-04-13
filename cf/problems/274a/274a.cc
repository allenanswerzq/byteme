/* created   : 2020-04-13 22:59:40
 * accepted  : 2020-04-13 23:35:24
 * author    : landcold7
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
  sort(all(a));
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (a[i] % k == 0 && !st.count(a[i] / k)) {
      st.insert(a[i]);
    }
  }
  cout << st.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
