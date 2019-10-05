//============================================================================
// Name        : 569b
// Date        : Sun May 19 18:26:56 CST 2019
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
  vi a(n + 1);
  set<int> st;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x > n) {
      continue;
    }
    if (!st.count(x)) {
      a[i] = x;
      st.insert(x);
    }
  }
  trace(st, a);
  set<int> unseen;
  for (int i = 1; i <= n; ++i) {
    if (!st.count(i)) {
      unseen.insert(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      a[i] = *unseen.begin();
      unseen.erase(unseen.begin());
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
