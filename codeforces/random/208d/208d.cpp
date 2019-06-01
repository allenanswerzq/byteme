//============================================================================
// Name        : 208d
// Date        : Tue May 21 11:05:18 CST 2019
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
  vi p(5);
  for (int i = 0; i < 5; ++i) {
    cin >> p[i];
  }
  vl cnt(5);
  ll money = 0;
  for (int i = 0; i < n; ++i) {
    money += a[i];
    while (1) {
      bool ok = 0;
      for (int j = 4; j >= 0; --j) {
        if (money >= p[j]) {
          int c = money / p[j];
          cnt[j] += c;
          money -= c * p[j];
          ok = 1;
          break;
        }
      }
      if (!ok) {
        break;
      }
    }
  }
  for (int i = 0; i < 5; ++i) {
    cout << cnt[i] << (i == 4 ? "\n" : " ");
  }
  output(money);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
