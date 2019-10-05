//============================================================================
// Name        : d
// Date        : Sat Apr 27 17:08:01 CST 2019
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
  ll n, k;
  cin >> n >> k;
  ll dn = k * (k - 1) / 2;
  ll up = pow(2, k) - 1;
  if (!(dn <= n && n <= up)) {
    output("NO");
    return;
  }
  trace(n, k, dn, up, n - dn, up - n);
  // 1 2 3 3
  // 1 2 4 8 16
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

