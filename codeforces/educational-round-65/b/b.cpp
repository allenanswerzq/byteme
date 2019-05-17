//============================================================================
// Name        : b
// Date        : Thu May 16 20:31:07 CST 2019
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

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int ret;
  cin >> ret;
  return ret;
}

void solve() {
  vi sp = {4, 8, 15, 16, 23, 42};
  map<int, pii> mp;
  for (int i = 0; i < sz(sp); ++i) {
    for (int j = i + 1; j < sz(sp); ++j) {
      mp[sp[i] * sp[j]] = {sp[i], sp[j]};
    }
  }
  trace(mp);
  vi r(7, 0);
  int x, y;
  x = query(1, 1); r[1] = sqrt(x);
  x = query(2, 2); r[2] = sqrt(x);
  x = query(3, 5);
  y = query(3, 6);
  pii a = mp[x], b = mp[y];
  if (a.x == b.x || a.x == b.y) {
    r[3] = a.x;
    r[5] = a.y;
    r[6] = a.x == b.x ? b.y : b.x;
  } else {
    r[3] = a.y;
    r[5] = a.x;
    r[6] = a.y == b.y ? b.x : b.y;
  }
  r[4] = accumulate(all(sp), 0) - accumulate(all(r), 0);
  cout << "! ";
  for (int i = 1; i <= 6; ++i) {
    cout << r[i] << (i == 6 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

