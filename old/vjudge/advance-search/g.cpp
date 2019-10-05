#include <bits/stdc++.h>
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

// TODO: still wrong answer...
struct Node {
  int x, y;
} ee, gf, ghosts[2];

const int maxn = 900;
char maze[maxn][maxn];
int m, n, level, cnt;
int visit[2][maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
deque<Node> dq[2];

bool check(Node &nd) {
  // If the node exceeds the scope.
  if (!(0 <= nd.x && nd.x < m && 0 <= nd.y && nd.y < n)) {
    return 0;
  }

  // If not walkable.
  if (maze[nd.x][nd.y] == 'X' || maze[nd.x][nd.y] == 'Z') {
    return 0;
  }

  // If the node will be killed by ghosts.
  fori (i, 0, 2) {
    if (abs(nd.x - ghosts[i].x) + abs(nd.y - ghosts[i].y) <= 2 * level) {
      return 0;
    }
  }

  return 1;
}

bool step(int ix) {
  int l = sz(dq[ix]);
  fori (i, 0, l) {
    Node cur = dq[ix].front(); dq[ix].pop_front();
    // trace(ix, cur.x, cur.y);

    // If the current positon will be killed.
    if (!check(cur)) {
      return 0;
    }

    fori (i, 0, 4) {
      Node nxt;
      nxt.x = cur.x + dx[i];
      nxt.y = cur.y + dy[i];
      if (check(nxt) && visit[ix][nxt.x][nxt.y] != cnt) {
        // If my gf already visited this position, then when i get to that
        // same position, we meet. and vice versa.
        if (visit[ix ^ 1][nxt.x][nxt.y] == cnt) {
          return 1;
        }
        dq[ix].pb(nxt);
        visit[ix][nxt.x][nxt.y] = cnt;
      }
    }
  }
  return 0;
}

int bfs() {
  dq[0].clear();
  dq[1].clear();
  // mst(visit, 0);

  dq[0].pb(ee);
  visit[0][ee.x][ee.y] = 1;

  dq[1].pb(gf);
  visit[1][gf.x][gf.y] = 1;

  level = 0;
  while (sz(dq[0]) || sz(dq[1])) {
    ++level;
    // Move the erriyue 3 steps, if any of those step meets then done.
    if (step(0)) {
      return level;
    }

    if (step(0)) {
      return level;
    }

    if (step(0)) {
      return level;
    }

    // Move the gf one step, if meets erriyue then done.
    if (step(1)) {
      return level;
    }
  }
  return -1;
}

void solve() {
  cin >> m >> n;
  int k = 0;
  fori (i, 0, m) {
    // TODO: understand why using cin acts very slow here.
    scanf("%s", maze[i]);
    fori (j, 0, n) {
      char ch = maze[i][j];
      if (ch == 'M') {
        ee.x = i;
        ee.y = j;
      } else if (ch == 'G') {
        gf.x = i;
        gf.y = j;
      } else if (ch == 'Z') {
        ghosts[k].x = i;
        ghosts[k].y = j;
        ++k;
      }
    }
  }

  // fori (i, 0, m) {
  //   par(maze[i], n, 1);
  // }

  output(bfs());
}

int main() {
  int t; cin >> t >> ws;
  cnt = 0;
  fori (i, 1, t + 1) {
    ++cnt;
    solve();
  }
  return 0;
}

