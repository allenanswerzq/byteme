/* created   : 2020-05-24 23:40:28
 * accepted  : 2020-05-25 00:58:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void merge_sort(vector<int>& a, vector<int>& t, int lo, int hi, ll& ans) {
  if (lo >= hi) return;
  int md = lo + (hi - lo) / 2;
  merge_sort(a, t, lo, md, ans);
  merge_sort(a, t, md + 1, hi, ans);
  int i = lo, j = md + 1;
  for (int k = lo; k <= hi; k++) {
    if (j > hi || (i <= md && a[i] <= a[j])) {
      t[k] = a[i++];
    }
    else {
      ans += (md - i + 1);
      t[k] = a[j++];
    }
  }
  for (int k = lo; k <= hi; k++) {
    a[k] = t[k];
  }
}

int n;

void solve() {
  vector<int> a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      if (x) {
        a.push_back(x);
      }
    }
  }
  vector<int> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      if (x) {
        b.push_back(x);
      }
    }
  }
  vector<int> t(n * n);
  ll cnt_a = 0;
  merge_sort(a, t, 0, (int) a.size() - 1, cnt_a);
  ll cnt_b = 0;
  merge_sort(b, t, 0, (int) b.size() - 1, cnt_b);
  // trace(n, cnt_a, cnt_b, a, b);
  if ((cnt_a & 1) ^ (cnt_b & 1)) {
    cout << "NIE\n";
  }
  else {
    cout << "TAK\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    solve();
  }
  return 0;
}
