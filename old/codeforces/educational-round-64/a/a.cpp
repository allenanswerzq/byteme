//============================================================================
// Name        : a
// Date        : Wed May  1 22:22:37 CST 2019
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
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n && a[i] == 2 && a[i + 1] == 3) {
      output("Infinite");
      return;
    }
    if (i + 1 < n && a[i] == 3 && a[i + 1] == 2) {
      output("Infinite");
      return;
    }
  }
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == 2 && a[i] == 1) {
      ret += 3;
    } else if (a[i - 1] == 1 && a[i] == 2) {
      ret += 3;
    } else if (a[i - 1] == 1 && a[i] == 3) {
      ret += 4;
    } else if (a[i - 1] == 3 && a[i] == 1) {
      ret += 4;
    }
  }
  output("Finite");
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

