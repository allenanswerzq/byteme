//=============================================================
// Name        : b
// Date        : Mon Jun 10 11:28:35 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

struct Node {
  string city;
  int score;
};

void solve() {
  int n;
  cin >> n;
  vector<pair<Node, int>> a(n);
  for (int i = 0; i < n; ++i) {
    string city;
    int score;
    cin >> city >> score;
    a[i].x = {city, score};
    a[i].y = i;
  }
  typedef pair<Node, int> psi;
  sort(a.begin(), a.end(), [](const psi& a, const psi& b){
    if (a.x.city == b.x.city) {
      return a.x.score > b.x.score;
    } else {
      return a.x.city < b.x.city;
    }
  });
  for (int i = 0; i < n; ++i) {
    cout << a[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
