//============================================================================
// Name        : c
// Date        : Wed Apr 17 18:21:13 CST 2019
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
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fori(i, s, n) prt(x, i, n)
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

vi e = {0, 1, 2, 0, 2, 1, 0};
int fun(vi& a, int x) {
  vi b = a;
  int ret = 0;
  while (1) {
    if (b[e[x]] == 0) {
      break;
    }
    ++ret;
    b[e[x]]--;
    x = (x + 1) % 7;
  }
  return ret;
}

void solve() {
  vi a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  while (a[0] > 3 && a[1] > 2 && a[2] > 2) {
    a[0] -= 3;
    a[1] -= 2;
    a[2] -= 2;
    ret += 7;
  }
  int tmp = 0;
  for (int i = 0; i < 7; ++i) {
    amax(tmp, fun(a, i));
  }
  output(ret + tmp);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

