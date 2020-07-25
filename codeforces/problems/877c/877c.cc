/* created   : 2020-05-05 21:53:43
 * accepted  : 2020-05-05 22:16:43
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a;
  for (int i = 2; i <= n; i += 2) {
    a.push_back(i);
  }
  for (int i = 1; i <= n; i += 2) {
    a.push_back(i);
  }
  for (int i = 2; i <= n; i += 2) {
    a.push_back(i);
  }
  cout << a.size() << "\n";
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
