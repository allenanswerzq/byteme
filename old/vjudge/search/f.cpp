// #include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <string>
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

bool prime(int a) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) return 0;
  }
  return 1;
}


char tt[10];
int visit[100000];
int cur, nxt;

void solve() {
  int a, b; cin >> a >> b;

  // trace(a, b);

  mst(visit, 0);
  deque<int> dq;
  dq.pb(a);
  visit[a] = 1;

  int level = 0;
  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      cur = dq.front(); dq.pop_front();
      if (cur == b) {
        output(level);
        return;
      }

      fori (i, 0, 4) {
        int tmp = cur;
        fori (k, 0, 4) {
          tt[3 - k] = tmp % 10 + '0';
          tmp /= 10;
        }
        
        fori (j, 0, 10) {
          if (i == 0 && j == 0) continue;
          tt[i] = j + '0';

          nxt = 0;
          fori (k, 0, 4) nxt = nxt * 10 + (tt[k] - '0');

          if (!visit[nxt] && prime(nxt)) {
            visit[nxt] = 1;
            dq.pb(nxt);
          }
        }
      }
    }
    ++level;
  }


}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    solve();
  }
  return 0;
}

