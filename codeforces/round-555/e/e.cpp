//============================================================================
// Name        : e
// Date        : Sat Apr 27 17:36:41 CST 2019
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
  vi b(n);
  multiset<int> st;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    st.insert(b[i]);
  }
  vi ret;
  for (int i = 0; i < n; ++i) {
    int d = (n - a[i]) % n;
    auto it = lower_bound(all(st), d);
    if (it == st.end()) {
      it = st.begin();
    }
    ret.pb((a[i] + *it) % n);
    st.erase(it);
  }
  for (int i = 0; i < sz(ret); ++i) {
    cout << ret[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

