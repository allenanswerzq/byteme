//============================================================================
// Name        : 616a
// Date        : Mon May 20 22:11:15 CST 2019
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

const int maxn = 1e6 + 7;

void solve() {
  string a, b;
  cin >> a >> b;
  reverse(all(a));
  reverse(all(b));
  while (sz(a) > 1 && a.back() == '0') {
    a.pop_back();
  }
  while (sz(b) > 1 && b.back() == '0') {
    b.pop_back();
  }
  // trace(a, b);
  int sa = sz(a);
  int sb = sz(b);
  if (sa > sb) {
    output(">");
  } else if (sa < sb) {
    output("<");
  } else {
    for (int i = sz(a) - 1; i >= 0; --i) {
      if (a[i] < b[i]) {
        output("<");
        return;
      } else if (a[i] > b[i]) {
        output(">");
        return;
      }
    }
    output("=");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
