//============================================================================
// Name        : 222a
// Date        : Tue May 21 20:05:38 CST 2019
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int b = a[--k];
  for (int i = k; i < n; ++i) {
    if (a[i] != b) {
      output(-1);
      return;
    }
  }
  for (int i = k - 1; i >= 0; --i) {
    if (a[i] != b) {
      output(i + 1);
      return;
    }
  }
  output(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
