/*
 * creat   : 2019-07-19 09:51:12
 * accept  : 2019-07-19 10:07:44
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

vector<int> sieve(int n) {
  vector<int> primes(n + 1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      for (int j = i + i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (primes[i]) {
      ans.push_back(i);
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  const int N = 1e5 + 7;
  vector<int> pr = sieve(N);
  auto go = [&](int x) {
    for (auto p : pr) {
      if (p >= x) {
        return p - x;
      }
    }
    assert(false);
    return -1;
  };
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      a[i][j] = go(x);
    }
  }
  trace(a);
  int ans = (1 << 30);
  for (int i = 0; i < n; ++i) {
    int tmp = accumulate(a[i].begin(), a[i].end(), 0);
    ans = min(ans, tmp);
  }
  for (int j = 0; j < m; ++j) {
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      tmp += a[i][j];
    }
    ans = min(ans, tmp);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
