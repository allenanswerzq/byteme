//============================================================================
// Name        : 43b
// Date        : Wed May 22 11:47:11 CST 2019
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
  getline(cin, a);
  getline(cin, b);
  vi ca(256);
  for (int i = 0; i < sz(a); ++i) {
    ca[a[i]]++;
  }
  vi cb(256);
  for (int i = 0; i < sz(b); ++i) {
    cb[b[i]]++;
  }
  for (int i = 0; i < sz(b); ++i) {
    if (b[i] != ' ' && cb[b[i]] > ca[b[i]]) {
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
