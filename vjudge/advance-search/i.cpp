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

char maze[2][12][12];
int visit[2][12][12];
int N, M, T, cnt;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int pl, px, py, cl, cx, cy;
struct Stat {
    int stat;
    int level;
};
deque<Stat> dq;

int encode(int l, int x, int y) {
    int ret = 0;
    ret <<= 4; ret |= l;
    ret <<= 4; ret |= x;
    ret <<= 4; ret |= y;
    return ret;
}

void decode(int st) {
    cy = st & 0xf;
    cx = (st >> 4) & 0xf;
    cl = (st >> 8) & 0xf;
}

void step(int l, int x, int y, int level) {
    if (0 <= x && x < N && 0 <= y && y < M &&
        visit[l][x][y] != cnt &&
        maze[l][x][y] != '*') {
        // trace(l, x, y, visit[l][x][y]);
        dq.pb(Stat{encode(l, x, y), level + 1});
        visit[l][x][y] = cnt;
    }
}

void bfs() {
    dq.clear();
    dq.pb(Stat{0, 0});
    visit[0][0][0] = cnt;
    while (sz(dq)) {
        Stat cur = dq.front(); dq.pop_front();
        decode(cur.stat);
        // trace(cnt, cl, cx, cy, cur.level, pl, px, py);
        if (cl == pl && cx == px && cy == py && cur.level <= T) {
            output("YES");
            return;
        }

        if (maze[cl][cx][cy] != '#') {
            fori (j, 0, 4) {
                step(cl, cx + dx[j], cy + dy[j], cur.level);
            }
        } else {
            if (maze[cl ^ 1][cx][cy] != '*' &&
                visit[cl ^ 1][cx][cy] != cnt) {
                dq.pb(Stat{encode(cl ^ 1, cx, cy), cur.level});
                visit[cl ^ 1][cx][cy] = cnt;
            }
        }
    }
    output("NO");
}


void solve() {
    cin >> N >> M >> T;
    fori (i, 0, 2) fori (j, 0, N) {
        scanf("%s", maze[i][j]);
        fori (k, 0, M) {
            char ch = maze[i][j][k];
            if (ch == 'P') {
                pl = i;
                px = j;
                py = k;
            }
        }
    }

   //  fori (i, 0, 2) fori (j, 0, N) {
   //      par(maze[i][j], M, 0);
   // }

    // trace(princess.l, princess.x, princess.y);

    bfs();
}

int main() {
    int c; cin >> c >> ws;
    cnt = 0;
    fori (i, 1, c + 1) {
        ++cnt;
        solve();
    }
    // while(1);
    return 0;
}

