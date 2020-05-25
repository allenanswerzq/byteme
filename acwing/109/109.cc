/* created   : 2020-05-24 21:27:49
 * accepted  : 2020-05-24 22:10:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n;
ll ans;

void merge_sort(vector<int>& a, int lo, int hi) {
  if (lo >= hi) return;
  int md = lo + (hi - lo) / 2;
  merge_sort(a, lo, md);
  merge_sort(a, md + 1, hi);
  int i = lo, j = md + 1;
  vector<int> t;
  for (int k = lo; k <= hi; k++) {
    if (j > hi || (i <= md && a[i] <= a[j])) {
      t.push_back(a[i++]);
    }
    else {
      ans += (md - i + 1);
      t.push_back(a[j++]);
    }
  }
  for (int k = lo; k <= hi; k++) {
    a[k] = t[k - lo];
  }
}

void solve() {
  vector<int> a(n);
  for (auto & x : a) {
    cin >> x;
  }
  ans = 0;
  merge_sort(a, 0, n - 1);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
