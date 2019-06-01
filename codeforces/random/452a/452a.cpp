//============================================================================
// Name        : 452a
// Date        : Fri Apr 26 21:20:54 CST 2019
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
  vector<string> a = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  int n;
  cin >> n;
  string s;
  cin >> s;
  int e = 0;
  for (int i = 0; i < n; ++i) {
    e += s[i] != '.';
  }
  for (auto it : a) {
    if (sz(it) != n) {
      continue;
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += it[i] == s[i];
    }
    if (c == e) {
      output(it);
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
