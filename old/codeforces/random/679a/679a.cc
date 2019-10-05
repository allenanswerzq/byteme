/*
 * creat   : 2019-07-16 06:57:12
 * accept  : 2019-07-16 07:46:35
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

const int hidden = 59;

bool query(int x) {
  cout << x << endl;
  string ret;
  cin >> ret;
  return ret == "yes";
  // return (hidden % x == 0);
}

void solve() {
  vector<int> pr = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
    37, 41, 43, 47
  };
  for (auto x : {4, 9, 25, 49}) {
    if (query(x)) {
      cout << "composite" << "\n";
      return;
    }
  }
  int cnt = 0;
  for (auto x : pr) {
    if (query(x)) {
      cnt++;
    }
  }
  cout << (cnt >= 2 ? "composite" : "prime") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
