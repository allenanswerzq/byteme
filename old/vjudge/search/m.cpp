// #include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
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

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

double tick() {
  static clock_t old;
  clock_t now = clock();
  double diff = 1.0 * (now - old);
  diff /= CLOCKS_PER_SEC;
  old = now;
  return diff;
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 110;
int s, n, m;
int visit[maxn][maxn][maxn];
deque<vi> dq;

void pour(int s, int a, int b) {
  if (!visit[s][a][b]) {
    // trace(s, a, b);
    visit[s][a][b] = 1;
    dq.pb({s, a, b});
  }
}

void solve() {
  if (s & 1) {
    output("NO");
    return;
  } 

  mst(visit, 0);
  dq.clear();
  dq.pb({s, 0, 0}); 
  visit[s][0][0] = 1;

  int level = 0;
  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      vi cur = dq.front(); dq.pop_front();
      int w = cur[0], x = cur[1], y = cur[2];
      // trace("cur", w, x, y, level);
      if (w == s / 2 || x == s / 2 || y == s / 2) {
        // Check whether we need to pour again to make two even cups.
        // One of these there cups must equal zero.
        output(level + (w && s && y));
        return;
      }

      // s --> n
      pour(w - (n - x), n, y);
      // s --> m
      pour(w - (m - y), x, m);

      // n --> s
      if (w + x > s) pour(s, x - (s - w), y);
      else pour(w + x, 0, y);

      // m --> s
      if (w + y > s) pour(s, x, y - (s - w));
      else pour(w + y, x, 0);

      // n --> m
      if (y + x > m) pour(w, x - (m - y), m);
      else pour(w, 0, y + x);
      // m --> n
      if (x + y > n) pour(w, n, y - (n - x));
      else pour(w, x + y, 0);
    } 
    ++level;
  }

  output("NO");

}

int main() {
  while (cin >> s >> n >> m) {
    if (!s && !n && !m) break;
    solve();
  }
  return 0;
}

