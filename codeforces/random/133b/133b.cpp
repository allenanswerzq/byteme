//============================================================================
// Name        : 133b
// Date        : Tue May 21 20:51:43 CST 2019
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

const int mod = 1000003;

void solve() {
  string s;
  cin >> s;
  map<char, string> mp;
  mp['>'] = "1000";
  mp['<'] = "1001";
  mp['+'] = "1010";
  mp['-'] = "1011";
  mp['.'] = "1100";
  mp[','] = "1101";
  mp['['] = "1110";
  mp[']'] = "1111";
  string p;
  for (int i = 0; i < sz(s); ++i) {
    p += mp[s[i]];
  }
  trace(p);
  ll ret = 0;
  for (int i = 0; i < sz(p); ++i) {
    ret = ((ret * 2) % mod + (p[i] - '0') % mod) % mod;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
