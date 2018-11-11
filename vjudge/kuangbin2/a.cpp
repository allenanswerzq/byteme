#include <set>
#include <queue>
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

int cantor(string arg) {
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
} Stat;
Stat path[maxn];

void bfs() {

  mst(visit, 0);
  mst(path, 0);
  queue<Stat> dq;
  Stat t;
  t.val = cantor("123456789");
  t.op = '#';
  t.pre = -1;
  path[t.val] = t;
  visit[t.val] = 1;
  dq.push(t);

  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      Stat cur = dq.front(); dq.pop();
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

        int hash = cantor(tt);
        if (visit[hash]) continue;
        visit[hash] = 1;

        Stat nxt;
        nxt.val = hash;
        nxt.op = ops[i],
        nxt.pre = cur.val;
        path[hash] = nxt;
        dq.push(nxt);
      }
    }
  }
}

void print_path(string& ss) {
  string bb;
  fori (i, 0, sz(ss)) {
    if (ss[i] == 'x') bb += '9';
    else if (ss[i] != ' ') bb += ss[i];
  }

  string r = "";
  int kt = cantor(bb);

  if (kt == 1) {
    output(r);
    return;
  }

  while (path[kt].op != '#') {
    r += string(1, path[kt].op);
    // string tt = inv_cantor(path[kt].val, 9);
    kt = path[kt].pre;
  }
  output(r != "" ? r : "unsolvable");
}

void solve(string& ss) {
  print_path(ss);
}

int main() {
  string ss;
  bfs();
  while (getline(cin, ss)) {
    solve(ss);
  }
  return 0;
}
