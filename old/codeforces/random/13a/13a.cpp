//=============================================================
// Name        : 13a
// Date        : Sat Jun  1 10:14:19 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int b = 2; b <= n - 1; ++b) {
    int t = n;
    vi a;
    while (t) {
      a.pb(t % b);
      t /= b;
    }
    sum += accumulate(a.begin(), a.end(), 0);
  }
  int g = gcd(sum,  n - 2);
  cout << sum / g << "/" << (n - 2) / g << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
