//============================================================================
// Name        : 960a
// Date        : Sat May 18 21:37:27 CST 2019
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
  string s;
  cin >> s;
  vi a(3);
  int idx = 0;
  for (int i = 0; i < 3; ++i) {
    while (idx < sz(s) && s[idx] == (char)('a' + i)) {
      a[i]++, idx++;
    }
    if (a[i] == 0) {
      output("NO");
      return;
    }
  }
  if (idx != sz(s)) {
    output("NO");
    return;
  }
  if (a[2] == a[0] || a[2] == a[1]) {
    output("YES");
    return;
  }
  output("NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
