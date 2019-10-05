//============================================================================
// Name        : 903b
// Date        : Sat May 18 19:19:40 CST 2019
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
  int h1, a1, c1;
  cin >> h1 >> a1 >> c1;
  int h2, a2;
  cin >> h2 >> a2;
  int ret = 0;
  vector<string> v;
  while (h2 > 0) {
    trace(h1, h2, a1, a2, c1);
    ret++;
    if (h2 - a1 <= 0) {
      v.pb("STRIKE");
      h2 -= a1;
      break;
    } else if (h1 - a2 > 0) {
      v.pb("STRIKE");
      h2 -= a1;
      h1 -= a2;
    } else {
      v.pb("HEAL");
      h1 += c1;
      h1 -= a2;
    }
  }
  output(ret);
  for (auto t : v) {
    output(t);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
