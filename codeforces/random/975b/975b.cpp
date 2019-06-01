//============================================================================
// Name        : 975b
// Date        : Tue May 21 11:46:13 CST 2019
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
  vl a(14);
  for (int i = 0; i < 14; ++i) {
    cin >> a[i];
  }
  auto get = [&](int ix) {
    vl b = a;
    ll cur = b[ix];
    b[ix] = 0;
    ll k = (cur - (14 - ix - 1)) / 14;
    ll d = (cur - (14 - ix - 1)) % 14;
    trace(ix, cur, k, d);
    for (int i = ix + 1; i < 14 && cur-- > 0; ++i) {
      b[i] += 1;
    }
    for (int i = 0; i < 14; ++i) {
      b[i] += k;
    }
    for (int i = 0; i < d; ++i) {
      b[i] += 1;
    }
    ll ret = 0;
    for (int i = 0; i < 14; ++i) {
      if (b[i] % 2 == 0) {
        ret += b[i];
      }
    }
    trace(b);
    return ret;
  };
  ll ret = 0;
  for (int i = 0; i < 14; ++i) {
    if (a[i] > 0) {
      ret = max(ret, get(i));
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
