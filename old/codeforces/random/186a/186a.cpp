//============================================================================
// Name        : 186a
// Date        : Fri Apr 26 19:10:36 CST 2019
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
  string a, b;
  cin >> a >> b;
  if (sz(a) != sz(b)) {
    output("NO");
    return;
  }
  vi ca(26), cb(26);
  for (int i = 0; i < sz(a); ++i) {
    ca[a[i] - 'a']++;
    cb[b[i] - 'a']++;
  }
  if (ca != cb) {
    output("NO");
    return;
  }
  int d = 0;
  for (int i = 0; i < sz(a); ++i) {
    d += a[i] != b[i];
  }
  output(d == 2 ? "YES" : "NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
