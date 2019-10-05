/*
 * created   : 2019-07-24 19:18:42
 * accepted  : 2019-07-24 21:15:15
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

struct node {
  string name;
  int ix;
  int score;
  friend ostream& operator<<(ostream& os, node& a) {
    os << a.name << " " << a.ix << " " << a.score;
    return os;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<node>> a(m);
  for (int i = 0; i < n; ++i) {
    node x;
    cin >> x.name >> x.ix >> x.score;
    x.ix--;
    a[x.ix].push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    sort(a[i].begin(), a[i].end(), [](node& x, node& y) {
      return x.score > y.score;
    });
  }
  trace(a);
  for (int i = 0; i < m; ++i) {
    int na = (int) a[i].size();
    if (na == 2) {
      cout << a[i][0].name << " " << a[i][1].name << "\n";
    }
    else if (na > 2) {
      if (a[i][1].score == a[i][2].score) {
        cout << "?" << "\n";
      }
      else {
        cout << a[i][0].name << " " << a[i][1].name << "\n";
      }
    }
    else {
      assert(false);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
