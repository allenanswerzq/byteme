//============================================================================
// Name        : 630j
// Date        : Sun May 19 17:40:20 CST 2019
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

ll gcd(ll a, ll b) {
  if (a < b) {
    swap(a, b);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

void solve() {
  ll n;
  cin >> n;
  ll ret = 1;
  for (int i = 2; i <= 10; ++i) {
    ret = lcm(ret, i);
  }
  output(n / ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
