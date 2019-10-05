// #include <bits/stdc++.h>
// #include <set>
// #include <deque>
#include <algorithm>
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

const int maxn = 100;
int visit[maxn];
int aa[maxn][3];
int src, cnt;

void dfs(int m, vi &path) {
  if (visit[m] == 1) {
    return;
  }

  visit[m] = 1;
  path.pb(m);

  if (sz(path) >= 20) {
    int t = path.back();
    if (t == aa[src][0] || t == aa[src][1] || t == aa[src][2]) {
      cout << cnt++ << ":  ";
      vi out = path;
      out.pb(src);
      fori (i, 0, sz(out)) {
        cout << out[i] << (i == sz(out) - 1 ? '\n': ' ');
      }
    }
  }

  fori (i, 0, 3) {
    int t = aa[m][i];
    if (!visit[t]) {
      dfs(t, path);
    }
  }

  path.pop_back();
  visit[m] = 0;
}

int main() {
  fori (i, 1, 21) {
    cin >> aa[i][0] >> aa[i][1] >> aa[i][2];
    sort(aa[i], aa[i] + 3);
  }

  while (cin >> src) {
    if (src) {
      vi path;
      mst(visit, 0);
      cnt = 1;
      dfs(src, path);
    } else {
      return 0;
    }
  }

  return 0;
}

