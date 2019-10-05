//============================================================================
// Name        : 225a
// Date        : Wed May 22 20:47:39 CST 2019
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
  int n;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    set<int> st = {a, b, 7 - a, 7 - b, m};
    vi v;
    for (int j = 1; j <= 6; ++j) {
      if (!st.count(j)) {
        v.pb(j);
      }
    }
    if (sz(v) == 1) {
      m = v[0];
    } else {
      output("NO");
      return;
    }
  }
  output("YES");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
