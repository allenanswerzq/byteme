//============================================================================
// Name        : f
// Date        : Sat Apr  6 15:46:45 CST 2019
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

const int maxn = 120;
const int inf = 0x3f3f3f3f;
vi a, sum;
int dp[maxn][maxn];
int rec(int lo, int hi) {
  int& ret = dp[lo][hi];
  if (lo >= hi) {
    return ret = 0;
  }
  if (ret != inf) {
    return ret;
  }
  for (int k = lo; k <= hi; ++k) {
    int tmp = (k - lo) * a[lo];
    tmp += rec(lo + 1, k) + rec(k + 1, hi);
    tmp += (k - lo + 1) * (sum[hi] - sum[k]);
    amin(ret, tmp);
  }
  return ret;
}

void solve(int cs) {
  int n; cin >> n;
  a = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sum = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    sum[i] = i == 0 ? a[i] : sum[i - 1] + a[i];
  }
  // trace(a, sum);
  mst(dp, 0x3f);
  jam(cs, rec(0, n - 1));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t >> ws;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}

