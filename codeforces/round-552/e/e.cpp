//============================================================================
// Name        : e
// Date        : Wed Apr 17 20:15:58 CST 2019
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
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : ""); }
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

void solve() {
  int n, k;
  cin >> n >> k;
  // set<pii> mp;
  map<int, int> mp;
  set<int> st;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    // mp.insert({a[i], i});
    mp[a[i]] = i;
    st.insert(i);
  }
  // trace(mp, st);
  int turn = 0;
  vi ret(n);
  while (sz(st)) {
    auto mx = *mp.rbegin();
    auto it = st.find(mx.y);
    vi del;
    for (int i = 0; i <= k; ++i) {
      ret[*it] = turn;
      del.pb(*it);
      if (it == st.begin()) {
        break;
      }
      it--;
    }
    it = st.find(mx.y);
    for (int i = 0; i < k; ++i) {
      ++it;
      if (it == st.end()) {
        break;
      }
      ret[*it] = turn;
      del.pb(*it);
    }
    turn ^= 1;
    for (auto ix : del) {
      // mp.erase({a[ix], ix});
      mp.erase(a[ix]);
      st.erase(ix);
    }
  }
  for (int i = 0; i < n; ++i) {
    ret[i]++;
  }
  par(ret, 0, n, 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
