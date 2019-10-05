//============================================================================
// Name        : 596a
// Date        : Mon Apr 29 22:11:07 CST 2019
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
  set<int> x, y;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  if (sz(x) != 2 || sz(y) != 2) {
    output(-1);
  } else {
    trace(x, y);
    int d = *next(x.begin(), 1) - *x.begin();
    int w = *next(y.begin(), 1) - *y.begin();
    output(d * w);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

