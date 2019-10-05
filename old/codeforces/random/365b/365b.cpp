//============================================================================
// Name        : 365b
// Date        : Sun Apr 21 18:50:58 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ret = n <= 2 ? n : 2;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    bool ok = 0;
    while (i + 2 < n && a[i] + a[i + 1] == a[i + 2]) {
      cnt++, i++;
      ok = 1;
    }
    if (ok) {
      ret = max(ret, cnt + 2);
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
