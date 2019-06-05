//=============================================================
// Name        : 402a
// Date        : Sat Jun  1 09:33:34 CST 2019
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

void solve() {
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int cnt_box = b / (k - 1);
  int last_sec = b % (k - 1) + 1;
  trace(cnt_box, last_sec);
  int ret = 0;
  if (cnt_box * k * v >= a) {
    ret = (a + k * v - 1) / (k * v);
  } else if (cnt_box * k * v + last_sec * v >= a) {
    ret = cnt_box + 1;
  } else {
    a = a - cnt_box * k * v - last_sec * v;
    ret = cnt_box + 1 + (a + v - 1) / v;
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
