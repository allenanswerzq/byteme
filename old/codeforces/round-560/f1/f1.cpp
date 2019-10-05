//============================================================================
// Name        : f1
// Date        : Fri May 17 20:57:01 CST 2019
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

const int maxn = 2e5 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pii> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i].x >> b[i].y;
    --b[i].x, --b[i].y;
  }
  auto check = [&](int day) {
    vi sale(maxn, -1);
    for (int i = 0; i < m; ++i) {
      int d = b[i].x, t = b[i].y;
      if (d <= day) {
      // The last day in which the `t`th good is for sale.
        sale[t] = max(sale[t], d);
      }
    }
    vector<vi> goods(maxn);
    for (int i = 0; i < n; ++i) {
      if (sale[i] != -1) {
      // Compute all the goods will be on sale for a specific day.
        goods[sale[i]].pb(i);
      }
    }
    vi need = a;
    int money = 0;
    for (int i = 0; i <= day; ++i) {
      money++;
      if (i >= maxn) {
        continue;
      }
      for (auto it : goods[i]) {
        if (money >= need[it]) {
          money -= need[it];
          need[it] = 0;
        } else {
          need[it] -= money;
          money = 0;
          break;
        }
      }
    }
    return accumulate(all(need), 0) * 2 <= money;
  };
  int lo = -1, hi = 4 * 1e5 + 7;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  output(hi + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

