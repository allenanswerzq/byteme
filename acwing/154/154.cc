/* created   : 2020-06-11 21:50:03
 * accepted  : 2020-06-11 22:42:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<int> st;
  vector<int> mi;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
    if (i >= k) {
      st.erase(st.find(a[i - k]));
    }
    if (i >= k - 1) {
      mi.push_back(*st.begin());
    }
  }
  st.clear();
  vector<int> mx;
  for (int i = 0; i < n; i++) {
    st.insert(-a[i]);
    if (i >= k) {
      st.erase(st.find(-a[i - k]));
    }
    if (i >= k - 1) {
      mx.push_back(-(*st.begin()));
    }
  }
  n = n - k + 1;
  for (int i = 0; i < n; i++) {
    cout << mi[i] << (i == n - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < n; i++) {
    cout << mx[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
