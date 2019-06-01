//============================================================================
// Name        : 639a
// Date        : Tue May 21 19:05:26 CST 2019
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
template<typename T, typename U, typename... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset<int> st;
  for (int i = 0; i < q; ++i) {
    int t, id;
    cin >> t >> id;
    --id;
    if (t == 1) {
      if (sz(st) < k) {
        st.insert(a[id]);
      } else {
        st.insert(a[id]);
        st.erase(st.begin());
      }
    } else {
      output(st.count(a[id]) ? "YES" : "NO");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
