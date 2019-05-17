//============================================================================
// Name        : c
// Date        : Thu May 16 21:26:25 CST 2019
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

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}

  bool same_set(int a, int b) {
    return find(a) == find(b);
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  UF uf(n + 1);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    int x, y;
    for (int j = 0; j < k; ++j) {
      if (j == 0) {
        cin >> x;
      } else {
        cin >> y;
        uf.join(x, y);
      }
    }
  }
  trace(uf.e);
  for (int i = 1; i <= n; ++i) {
    cout << uf.size(i) << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

