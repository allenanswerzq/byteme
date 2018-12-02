#include <set>
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

const int maxn = 500000;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char ops[] = {'d', 'u', 'l', 'r'};
int facts[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
int visit[maxn];
string ss;

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
  char op;
  int pre;
  Stat(int v = 0, char o = 0, int p = 0) : val(v), op(o), pre(p) {}
} Stat;
Stat path[maxn], cur;

void bfs() {
  mst(visit, 0);

  deque<Stat> dq;
  string goal = "123456789";
  Stat t(cantor(goal), '#', -1);

  path[t.val] = t;
  visit[t.val] = 1;
  dq.pb(t);

  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      Stat cur = dq.front(); dq.pop_front();
      string cs = inv_cantor(cur.val, 9);
      int p = 0;
      fori (i, 0, 9) if (cs[i] == '9') p = i;
      int x = p / 3, y = p % 3;

      fori (i, 0, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!(0 <= nx && nx < 3 && 0 <= ny && ny < 3)) continue;
        int np = nx * 3 + ny;
        string tt = cs;
        swap(tt[p], tt[np]);

        int hh = cantor(tt);
        if (visit[hh]) continue;
        visit[hh] = 1;
        Stat nxt(hh, ops[i], cur.val);
        path[hh] = nxt;
        dq.pb(nxt);
      }
    }
  }
}

void print_path() {
  string bb = "", rr = "";
  fori (i, 0, sz(ss)) {
    if (ss[i] == 'x') bb += '9';
    else if (ss[i] != ' ') bb += ss[i];
  }

  int kt = cantor(bb);

  while (path[kt].op != '#' && path[kt].op) {
    rr += string(1, path[kt].op);
    kt = path[kt].pre;
  }

  output(rr != "" ? rr : kt == 1 ? rr : "unsolvable");
}

void solve() {
  print_path();
}

int main() {
  bfs();
  while (getline(cin, ss)) {
    solve();
  }
  return 0;
}