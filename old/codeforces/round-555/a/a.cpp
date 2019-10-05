//============================================================================
// Name        : a
// Date        : Fri Apr 26 22:33:44 CST 2019
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

int add(int x) {
  int r = x + 1;
  while (1) {
    if (r % 10 == 0) {
      r /= 10;
    } else {
      break;
    }
  }
  return r;
}

void solve() {
  int n;
  cin >> n;
  set<int> st;
  while (1) {
    if (st.count(n)) {
      break;
    }
    st.insert(n);
    n = add(n);
  }
  output(sz(st));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
