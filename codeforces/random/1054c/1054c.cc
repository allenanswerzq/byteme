/*
 * created   : 2019-08-06 09:26:32
 * accepted  : 2019-08-06 12:55:42
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> ans(n);
  int cnt = -1;
  for (int i = 0; i < n; i++) {
    vector<int> mx;
    for (int j = 0; j < n; j++) {
      if (a[j] == 0 && b[j] == 0 && !ans[j]) {
        ans[j] = cnt;
        mx.push_back(j);
      }
    }
    cnt--;
    int nm = (int) mx.size();
    if (nm == 0) {
      break;
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < nm && !ans[j]; k++) {
        if (j < mx[k]) {
          b[j]--;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < nm && !ans[j]; k++) {
        if (j > mx[k]) {
          a[j]--;
        }
      }
    }
  }
  trace(ans, a, b, cnt);
  int ma = *max_element(a.begin(), a.end());
  int mb = *min_element(a.begin(), a.end());
  if (ma != 0 || mb != 0) {
    cout << "NO" << "\n";
    return;
  }
  ma = *max_element(b.begin(), b.end());
  mb = *min_element(b.begin(), b.end());
  if (ma != 0 || mb != 0) {
    cout << "NO" << "\n";
    return;
  }
  int mi = *min_element(ans.begin(), ans.end());
  assert(mi <= 0);
  cout << "YES" << "\n";
  for (int i = 0; i < n; i++) {
    ans[i] += -mi + 1;
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
