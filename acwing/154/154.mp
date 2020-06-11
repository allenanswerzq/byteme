/* created   : 2020-06-11 21:50:03
 * accepted  : 2020-06-11 22:08:04
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<int> go_max(vector<int>& a, int n, int k) {
  deque<int> qu;
  qu.push_back(0);
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    while (qu.size() && i - qu.front() + 1 > k) {
      qu.pop_front();
    }
    assert(qu.size());
    int mx = max(a[i], a[qu.front()]);
    if (i >= k - 1) {
      ans.push_back(mx);
    }
    while (qu.size() && a[i] >= a[qu.back()]) {
      qu.pop_back();
    }
    qu.push_back(i);
  }
  return ans;
}

vector<int> go_min(vector<int>& a, int n, int k) {
  deque<int> qu;
  qu.push_back(0);
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    while (qu.size() && i - qu.front() + 1 > k) {
      qu.pop_front();
    }
    int mx = min(a[i], a[qu.front()]);
    if (i >= k - 1) {
      ans.push_back(mx);
    }
    while (qu.size() && a[i] <= a[qu.back()]) {
      qu.pop_back();
    }
    qu.push_back(i);
  }
  return ans;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
    return;
  }
  vector<int> mx = go_max(a, n, k);
  vector<int> mi = go_min(a, n, k);
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
