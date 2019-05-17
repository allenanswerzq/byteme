//============================================================================
// Name        : a
// Date        : Mon Apr 29 22:35:02 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, m, r;
  cin >> n >> m >> r;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vi b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int ret = r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ret = max(ret, r / a[i] * b[j] + r % a[i]);
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

