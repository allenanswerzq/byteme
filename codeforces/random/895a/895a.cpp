//============================================================================
// Name        : 895a
// Date        : Tue May 21 14:19:38 CST 2019
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
template<typename T, typename U, typename... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  vi pr(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pr[i + 1] = pr[i] + a[i];
  }
  auto get = [&](int i, int j) {
    return pr[j + 1] - pr[i];
  };
  int ret = 360;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ret = min(ret, 2 * abs(get(i, j) - 180));
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
