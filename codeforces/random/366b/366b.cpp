//============================================================================
// Name        : 366b
// Date        : Tue May 28 19:27:44 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
template<class T> void puts(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void puts(T t, U u, G... g) { cout << t << " "; puts(u, g...); }

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  vector<ll> sum(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum[i % k] += a[i];
  }
  auto ret = min_element(sum.begin(), sum.end()) - sum.begin();
  puts(ret + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
