//============================================================================
// Name        : 127b
// Date        : Sat May 25 13:51:58 CST 2019
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
  vi cnt(120);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ret = 0;
  for (int i = 1; i < 120; ++i) {
    ret += cnt[i] / 2;
  }
  output(ret / 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
