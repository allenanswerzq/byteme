//============================================================================
// Name        : 505a
// Date        : Sun May 19 22:49:09 CST 2019
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
  auto check = [](string& s) {
    int lo = 0, hi = sz(s) - 1;
    while (lo < hi) {
      if (s[lo++] != s[hi--]) {
        return 0;
      }
    }
    return 1;
  };
  for (int i = 0; i <= sz(s); ++i) {
    for (int j = 0; j < 26; ++j) {
      string t = s;
      t.insert(t.begin() + i, (char)('a' + j));
      if (check(t)) {
        output(t);
        return;
      }
    }
  }
  output("NA");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
