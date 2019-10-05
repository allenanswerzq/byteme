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

const int maxn = 1100;
int r, c;
char gg[maxn][maxn];
int visit[maxn][maxn];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct Stat {
  int x, y;
  int who;
  Stat(): x(-1), y(-1), who(-1) {}
  Stat(int x, int y, int w) : x(x), y(y), who(w) {}
};

void solve() {
  cin >> r >> c;

  Stat joe(-1, -1, 1);
  // The case that has many fires.
  vector<Stat> fires;

  // trace(joe.x, joe.y, fire.x, fire.y);
  fori (i, 0, r) fori (j, 0, c) {
    cin >> gg[i][j];
    if (gg[i][j] == 'J') joe.x = i, joe.y = j;
    if (gg[i][j] == 'F') {
      Stat fire(i, j, 0);
      fires.pb(fire);
    }
  }

  // trace(r, c);

  mst(visit, 0);
  deque<Stat> dq;
  dq.clear();
  fori (i, 0, sz(fires)) {
    Stat fire = fires[i];
    dq.pb(fire);
    visit[fire.x][fire.y] = 2;
  }
  // Must access Fire first. 
  dq.pb(joe);
  visit[joe.x][joe.y] = 1;

  int level = 0;
  while (sz(dq)) {
    int l = sz(dq); 
    // bool ok = 0;
    fori (i, 0, l) {
      Stat cur = dq.front(); dq.pop_front();
      int x = cur.x, y = cur.y; 
      // trace(x, y, cur.who, level);

      // Joe reaches to the border of the maze.
      if (cur.who == 1 && (x == r - 1 || x == 0 || y == 0 || y == c - 1)) {
        output(++level);
        return;
      }

      fori (i, 0, 4) {
        Stat nxt;
        int nx = x + dx[i], ny = y + dy[i];
        nxt.x = nx, nxt.y = ny;

        if (!(0 <= nx && nx < r && 0 <= ny && ny < c)) continue;
        if (gg[nx][ny] == '#') continue;

        // Fire
        if (cur.who == 0) {
          nxt.who = 0;
          if (visit[nx][ny] == 2) continue;
          visit[nx][ny] = 2;
          dq.pb(nxt);
        }

        // Joe
        if (cur.who == 1) {
          nxt.who = 1;
          if (visit[nx][ny] == 2) continue;
          if (visit[nx][ny] == 1) continue;
          visit[nx][ny] = 1;
          dq.pb(nxt);
        }

        // trace(nxt.x, nxt.y, nxt.who);
      }

    }

    // // Cannt find a square for Joe to move next.
    // if (ok) {
    //   output("IMPOSSIBLE");
    //   return;
    // } 

    ++level;
  }

  output("IMPOSSIBLE");
}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    solve();
  }
  return 0;
}

