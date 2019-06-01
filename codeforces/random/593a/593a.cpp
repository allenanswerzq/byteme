//============================================================================
// Name        : 593a
// Date        : Tue May 21 16:43:38 CST 2019
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
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    for (char b = c + 1; b <= 'z'; ++b) {
      int tmp = 0;
      for (int i = 0; i < n; ++i) {
        bool ok = 1;
        string s = a[i];
        for (int j = 0; j < sz(s); ++j) {
          if (s[j] != c && s[j] != b) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          tmp += sz(s);
        }
      }
      ret = max(ret, tmp);
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
