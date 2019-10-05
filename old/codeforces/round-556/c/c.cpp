//============================================================================
// Name        : c
// Date        : Mon Apr 29 23:01:50 CST 2019
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

vector<int> prime;
void sieve(int n) {
  prime = vi(n + 1, 1);
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (prime[i] == 0) {
      continue;
    }
    for (int j = i + i; j <= n; j += i) {
      prime[j] = 0;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  int maxn = (int)2e6 + 7;
  sieve(maxn);
  int a = 0, b = 0;
  vi g(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      a++;
    } else {
      b++;
    }
    g[i] = x;
  }
  trace(a, b);
  // sort(all(g));
  vi ret;
  int pre = 0, cnt = 0;
  for (int i = 1; i < maxn; ++i) {
    if (a <= 0 && b <= 0) {
      break;
    }
    // trace(i);
    if (prime[i]) {
      int d = (i - pre);
      int t = d / 2;
      // trace(i, d, pre, a, b, t);
      if (b >= t) {
        b -= t;
        while (t-- > 0) {
          ret.pb(2);
        }
        if (d % 2) {
          if (a <= 0) {
            break;
          }
          a--;
          ret.pb(1);
        }
      } else {
        t = d - 2 * max(b, 0);
        // assert(d > 0);
        // trace(ret);
        // trace('a', i, d, pre, a, b, t);
        while (b-- > 0) {
          ret.pb(2);
        }
        if (a >= t) {
          a -= t;
          while (t-- > 0) {
            ret.pb(1);
          }
        } else {
          break;
        }
      }
      cnt++;
      pre = i;
      // trace(i, d, pre, a, b);
      // trace(ret);
    }
  }
  // trace(cnt);
  // output(sz(ret));
  while (a-- > 0) {
    ret.pb(1);
  }
  while (b-- > 0) {
    ret.pb(2);
  }
  for (int i = 0; i < sz(ret); ++i) {
    cout << ret[i] << (i == sz(ret) - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

