//============================================================================
// Name        : 722b
// Date        : Mon May 20 09:57:37 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // Get the last whitespace char.
  cin >> ws;
  set<char> v = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    int cnt = 0;
    for (auto c : s) {
      if (v.count(c)) {
        cnt++;
      }
    }
    // trace(s, cnt, a[i]);
    if (cnt != a[i]) {
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
