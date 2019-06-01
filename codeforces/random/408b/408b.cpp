//============================================================================
// Name        : 408b
// Date        : Wed May 22 20:30:45 CST 2019
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
  string a, b;
  cin >> a >> b;
  vi ca(26), cb(26);
  for (int i = 0; i < sz(a); ++i) {
    ca[a[i] - 'a']++;
  }
  for (int i = 0; i < sz(b); ++i) {
    cb[b[i] - 'a']++;
  }
  vi was(26);
  int ret = 0;
  for (int i = 0; i < sz(b); ++i) {
    if (cb[b[i] - 'a'] > 0 && ca[b[i] - 'a'] == 0) {
      output(-1);
      return;
    } else {
      if (!was[b[i] - 'a']) {
        ret += min(ca[b[i] - 'a'], cb[b[i] - 'a']);
        was[b[i] - 'a'] = 1;
      }
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
