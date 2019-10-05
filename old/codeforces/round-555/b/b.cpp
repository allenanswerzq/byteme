//============================================================================
// Name        : b
// Date        : Fri Apr 26 22:56:27 CST 2019
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
  int n;
  cin >> n;
  string a;
  cin >> a;
  vi b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i] - '0';
  }
  vi d(10);
  for (int i = 1; i <= 9; ++i) {
    cin >> d[i];
  }
  vector<pii> p;
  string rs = a;
  for (int i = 0; i < n; ++i) {
    int c = 0, j = i, same = 0;
    while (j < n && d[b[j]] >= b[j]) {
      same += d[b[j]] == b[j];
      c++, j++;
    }
    if (same != c) {
      for (int k = i; k < i + c; ++k) {
        rs[k] = ((char)(d[b[k]] + '0'));
      }
      break;
    }
    i = j;
  }
  output(rs);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
