//============================================================================
// Name        : e
// Date        : Fri May 17 19:08:04 CST 2019
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

const int mod = 998244353;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vi b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(rall(b));
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
  // Contribute to sum.
    v[i] = (ll)a[i] * (i + 1) * (n - i);
  }
  sort(all(v));
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += b[i] * (v[i] % mod);
    ret %= mod;
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
