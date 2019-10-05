// #include <bits/stdc++.h>
#include <vector>
#include <deque>
#include <iostream>
#include <cstring>
using namespace std;

#define fi first
#define se second
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

int aa[5][5];
int visit[5][5];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Stat {
  int val;
  Stat *pre;
  Stat(int val=0, Stat *pre=NULL) : val(val), pre(pre) {}
};

void path(Stat *st) {
  string r = ""; 
  while (st) {
    char x = st->val / 5, y = st->val % 5;
    // trace(x, y);
    r = "(" + string(1, x + '0') + ", " + string(1, y + '0') + ")\n" + r;  
    st = st->pre;
  }
  output(r.substr(0, sz(r) - 1));
}

void solve() {
  fori (i, 0, 5) fori (j, 0, 5)
    cin >> aa[i][j];

  mst(visit, 0);
  deque<Stat*> dq;
  dq.clear();
  Stat *st = new Stat();
  // trace(st->val, st->pre);
  dq.pb(st);
  visit[0][0] = 1;

  int level = 0;
  while (sz(dq)) {
    ++level;
    int l = sz(dq);
    fori (i, 0, l) {
      Stat *cur = dq.front(); dq.pop_front();
      if (cur->val == 4 * 5 + 4) {
        path(cur);
        return;
      }  

      int x = cur->val / 5, y = cur->val % 5;
      // trace(x, y, level);
      fori (i, 0, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!(0 <= nx && nx < 5 && 0 <= ny && ny < 5)) continue;
        if (visit[nx][ny] || aa[nx][ny] == 1) continue;
        visit[nx][ny] = 1;
        Stat *nxt = new Stat(nx * 5 + ny, cur);
        // trace(nx, ny);
        dq.pb(nxt);
      }
    }
  }

}

int main() {
  solve();
  return 0;
}

