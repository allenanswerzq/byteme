// #include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//   cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//   const char* split = strchr(names + 1, ',');
//   cout.write(names, split - names) << ": " << arg << " |";
//   _f(split, args...);
// }

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n;
int visit[220];

struct Point {
  char aa[220];
  int mod;
};

void solve() {
  Point p;
  p.mod = 1;
  p.aa[0] = '1';
  mst(visit, 0);

  deque<Point> dq;
  dq.pb(p);
  visit[1] = 1;

  int level = 0;
  while (sz(dq)) {
    ++level;
    int l = sz(dq);
    fori (i, 0, l) {
      Point cur = dq.front(); dq.pop_front();
      if (cur.mod == 0) {
        fori (j, 0, level)
          cout << cur.aa[j] << (j == level - 1 ? "\n": "");
        return;
      }

      fori (j, 0, 2) {
        Point nxt = cur;
        nxt.aa[level] = j == 0 ? '0' : '1';
        if (j == 0) nxt.mod = (nxt.mod * 10) % n;
        if (j == 1) nxt.mod = (nxt.mod * 10 + 1) % n;
        if (!visit[nxt.mod]) {
          visit[nxt.mod] = 1;
          dq.pb(nxt);
        }
      }

    }
  }
}

int main() {
  while (cin >> n) {
    if (!n) break;
    solve();
  }
  return 0;
}


