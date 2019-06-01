//============================================================================
// Name        : 931b
// Date        : Tue May 21 10:19:30 CST 2019
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
  int n, a, b;
  cin >> n >> a >> b;
  --a, --b;
  int cnt = 0;
  while (n > 0) {
    cnt++;
    if (a / 2 == b / 2) {
      if (n == 2) {
        output("Final!");
        return;
      } else {
        output(cnt);
        return;
      }
    }
    n -= n / 2;
    a /= 2, b /= 2;
  }
  assert(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
