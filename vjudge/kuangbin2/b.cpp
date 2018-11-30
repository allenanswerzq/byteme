#include <set>
#include <deque>
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
#define codejam(ix, v) cout << "Case " << (ix) << ": " << (v) << '\n'
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

// TODO: this code still tle...
int facts[12];

void fact() {
  facts[0] = 1;
  fori (i, 1, 12) {
    facts[i] = facts[i - 1] * i;
  }
}

int cantor(string& arg) {
  int ret = 1, len = sz(arg);
  fori (i, 0, len) {
    int cnt = 0;
    fori (k, i + 1, len) if (arg[i] > arg[k]) cnt++;
    ret = ret + facts[len - i - 1] * cnt;
  }
  return ret;
}

string inv_cantor(int num, int len) {
  string ret = "";
  num = num - 1;
  bool ok[12] = { 0 };
  fori (i, 0, len) {
    int mid = 0, cnt = num / facts[len - i - 1];
    while (++mid) if (!ok[mid]) {
      if (cnt == 0) break;
      cnt--;
    }
    ret += string(1, (char)('0' + mid));
    ok[mid] = 1;
    num = num % facts[len - i - 1];
  }
  return ret;
}

typedef struct Stat {
  int val;
  char pa;
  char pb;
  int pre;
  int nxt;
  Stat(int v = 1, char a = '#', char b = '#', int p = -1, int n = -1)
    : val(v), pa(a), pb(b), pre(p), nxt(n) {}
} Stat;

const int maxn = 500000;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char ops[][4] = {{'d', 'l', 'r', 'u'}, {'u', 'r', 'l', 'd'}};
int visit[2][maxn];
string ss, aa, bb;
Stat path[maxn];

void strip(string& aa) {
  fori (i, 0, sz(aa)) {
    if (aa[i] == 'X') aa[i] = '9';
  }
}

void print_path(int ii, int vv) {
  string rr = "";
  int kt = vv;

  while (path[kt].pa != '#' && path[kt].pa) {
    rr += string(1, path[kt].pa);
    kt = path[kt].pre;
  }

  reverse(all(rr));
  // trace(rr, sz(rr));
  kt = vv;
  while (path[kt].pb != '#' && path[kt].pb) {
    // trace(path[kt].pb, (int)(path[kt].pb));
    rr += string(1, path[kt].pb);
    kt = path[kt].nxt;
  }

  // trace(rr);
  codejam(ii, sz(rr));
  output(rr);
}

void bfs(int ii) {
  mst(visit, 0);
  mst(path, 0);

  deque<Stat> dq[2];
  Stat a(cantor(aa), '#');
  Stat b(cantor(bb), '#');

  path[a.val] = a;
  path[b.val] = b;
  visit[0][a.val] = 1;
  visit[1][b.val] = 1;
  dq[0].pb(a);
  dq[1].pb(b);

  int level = 0;
  while (sz(dq[0]) && sz(dq[1])) {

    fori (i, 0, 2) {
      fora (v, dq[0]) fora (u, dq[1]) {
        if (v.val == u.val) {
          print_path(ii, v.val);
          return;
        }
      }

      int l = sz(dq[i]);
      fori (j, 0, l) {
        Stat cur = dq[i].front(); dq[i].pop_front();
        string cs = inv_cantor(cur.val, 9);
        // trace(cur.val, cs);
        int p = 0;
        fori (t, 0, 9) if (cs[t] == '9') p = t;
        int x = p / 3, y = p % 3;

        fori (k, 0, 4) {
          int nx = x + dx[k], ny = y + dy[k];
          if (!(0 <= nx && nx < 3 && 0 <= ny && ny < 3)) continue;
          int np = nx * 3 + ny;
          string tt = cs;
          swap(tt[p], tt[np]);

          int hh = cantor(tt);
          if (visit[i][hh]) continue;
          visit[i][hh] = 1;

          Stat nst = path[hh];
          nst.val = hh;
          if (i == 0) nst.pre = cur.val, nst.pa = ops[i][k];
          if (i == 1) nst.nxt = cur.val, nst.pb = ops[i][k];
          path[hh] = nst;
          dq[i].pb(nst);
        }
      }
    }
    ++level;
  }
}

int main() {
  fact();
  int t; cin >> t;
  fori (i, 1, t + 1) {
    cin >> aa >> bb;
    strip(aa), strip(bb);
    // trace(i, aa, bb);
    bfs(i);
  }
  return 0;
}
