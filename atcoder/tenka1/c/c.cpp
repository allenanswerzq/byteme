//============================================================================
// Name        : c
// Date        : Sun Apr 21 15:39:56 CST 2019
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
  string s;
  cin >> s;
  vi a(n + 1);
  for (int i = 0; i < n; ++i) {
    a[i + 1] = a[i] + (s[i] == '#');
  }
  vi b(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    b[i] = b[i + 1] + (s[i] == '.');
  }
  trace(a, b);
  int ret = n;
  for (int i = 0; i < n; ++i) {
    ret = min(ret, a[i] + b[i + 1]);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
