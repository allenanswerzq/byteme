//============================================================================
// Name        : c
// Date        : Fri Apr 19 10:33:44 CST 2019
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
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void put(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void put(T t, U u, Args... args) { cout << t << " "; put(u, args...); }

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

const int mod = (int) 1e9 + 7;

ll get(ll a, ll n) {
  // s = (a1 + an) * n / 2;
  // s = (a1 + a1 + (n - 1) * d) * n / 2
  return ((a % mod + (n - 1) % mod) % mod * (n % mod)) % mod;
}

ll solve(ll x) {
  int turn = 1;
  ll ret = 0;
  ll odd = 1, even = 2;
  for (ll len = 1, pos = 1; pos <= x; len <<= 1) {
    ll n = min(len, x - pos + 1);
    if (turn) {
      ret = (ret + get(odd, n)) % mod;
      odd += 2 * n;
    } else {
      ret = (ret + get(even, n)) % mod;
      even += 2 * n;
    }
    pos += n;
    turn ^= 1;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  put((solve(b) - solve(a - 1) + mod) % mod);
  return 0;
}
