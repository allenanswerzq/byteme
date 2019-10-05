//============================================================================
// Name        : 347b
// Date        : Sat Apr 27 20:29:49 CST 2019
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
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[a[i]] = i;
  }
  trace(a, b);
  int ret = 0, ok = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == i) {
      ret++;
    } else if (b[b[i]] == i) {
      ok = 1;
    }
  }
  trace(ret, ok);
  if (ret == n) {
    output(ret);
  } else if (ok) {
    output(ret + 2);
  } else {
    output(ret + 1);
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

