//============================================================================
// Name        : 740b
// Date        : Sat Apr 27 23:16:10 CST 2019
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
  int n, m;
  cin >> n >> m;
  vi a(n), pre(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pre[i + 1] = pre[i] + a[i];
  }
  auto get = [&](int l, int r) {
    return pre[r] - pre[l - 1];
  };
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    ret += get(x, y) > 0 ? get(x, y) : 0;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

