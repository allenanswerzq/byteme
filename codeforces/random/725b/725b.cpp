//============================================================================
// Name        : 725b
// Date        : Wed May 22 10:05:39 CST 2019
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
  ll row;
  char seat;
  cin >> row >> seat;
  trace(row, seat);
  // 1 3 2 4 | 5 7 6 8 | 9 11 10 12 |
  // 0 2 1 3 | 4 6 5 7 | 8 10 9  11 |
  row--;
  ll ret = row / 4 * 16;
  ret += row % 2 ? 7 : 0;
  vi v = {4, 5, 6, 3, 2, 1};
  ret += v[seat - 'a'];
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
