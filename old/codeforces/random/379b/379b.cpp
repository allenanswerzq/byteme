//============================================================================
// Name        : 379b
// Date        : Sat Apr 27 21:45:20 CST 2019
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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  string ret;
  int dir = 1;
  int i = 0;
  while (1) {
    if (a[i]-- > 0) {
      ret.pb('P');
    }
    if (*max_element(all(a)) == 0) {
      break;
    }
    i += dir;
    ret.pb(dir == 1 ? 'R' : 'L');
    if (i == n - 1) {
      dir = -1;
    } else if (i == 0) {
      dir = 1;
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

