//============================================================================
// Name        : b
// Date        : Mon Apr  8 20:56:15 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vi a;
int ret;
void rec(int p, int path, vector<bool>& visit) {
  // trace(p, path);
  if (p == sz(a) - 1) {
    int cnt = 0;
    for (int i = 0; i < sz(a); ++i) {
      if (!visit[i]) {
        path += a[i];
        ++cnt;
      }
    }
    assert(cnt == 1);
    amin(ret, path);
    return;
  }
  for (int i = 0; i < sz(a); ++i) {
    if (!visit[i]) {
      visit[i] = 1;
      int tmp = a[i];
      for (int j = a[i]; j % 10 != 0; ++j) {
        ++tmp;
      }
      rec(p + 1, path + tmp, visit);
      visit[i] = 0;
    }
  }
}

void solve() {
  int n = 5;
  a = vi(n);
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
  }
  ret = (int) 1e9 + 7;
  vector<bool> visit(n);
  rec(0, 0, visit);
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

