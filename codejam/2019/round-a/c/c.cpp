//============================================================================
// Name        : c
// Date        : Sat Apr 20 21:54:03 CST 2019
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

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

int n, q;
vector<pii> seg;

bool check(int x) {
  vector<int> val(q, 0);
  set<pair<int, int>> st;
  int last = 0;
  for (auto sg : seg) {
    int l = sg.x, r = sg.y;
    while (!st.empty()) {
      auto it = *st.begin();
      if (it.x <= l) {
        val[it.y] += max(it.x - last, 0);
        last = max(last, it.x);
        st.erase(it);
      } else {
        break;
      }
    }
  }
}

void solve(int tc) {
  cin >> n >> q;
  seg = vector<pii>(q);
  for (int i = 0; i < q; ++i) {
    cin >> seg[i].x >> seg[i].y;
    seg[i].x--;
  }
  sort(all(seg));
  trace(seg);
  int lo = 0, hi = (1 << 30);
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << "Case #" << tc << ":" << lo << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
