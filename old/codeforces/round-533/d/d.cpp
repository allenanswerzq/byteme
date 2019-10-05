//============================================================================
// Name        : d
// Date        : Mon Jan 21 14:31:34 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << '\n'
#define par(x, s, n, v) if(v) pvar(x); fori(a, s, n) prt(x, a, n) cout << '\n'

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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef struct Stat {
    int x, y, t;
} Stat;

const int maxn = 1007;
const int step = 1100;

string gg[maxn];
int speed[maxn];
bool visit[maxn][maxn];
vi pos[10];
int cnt[10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, p;

bool check(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool bfs(int src) {
    deque<Stat> dq;
    while (sz(pos[src])) {
        int b = pos[src].back();
        int x = b / step, y = b % step;
        dq.pb({x, y, 0});
        pos[src].pop_back();
    }

    bool update = 0;
    while (sz(dq)) {
        Stat st = dq.front(); dq.pop_front();
        int x = st.x, y = st.y, t = st.t;
        fori (i, 0, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && !visit[nx][ny] && t + 1 <= speed[src]) {
                visit[nx][ny] = 1;
                dq.pb({nx, ny, t + 1});
                pos[src].pb(nx * step + ny);
                update = 1;
                cnt[src]++;
            }
        }
    }
    return update;
}

void solve() {
    cin >> n >> m >> p;

    fori (i, 1, p + 1) {
        cin >> speed[i];
    }

    fori (i, 0, n) {
        cin >> gg[i];
    }

    mst(visit, 0);
    fori (i, 0, n) {
        fori (j, 0, m) {
            char ch = gg[i][j];
            if (ch == '#') {
                visit[i][j] = 1;
            } else if (ch == '.') {
                visit[i][j] = 0;
            } else if ('1' <= ch && ch <= '9') {
                visit[i][j] = 1;
                pos[ch - '0'].pb(i * step + j);
                cnt[ch - '0']++;
            }
        }
    }

    bool ok = 1;
    while (ok) {
        ok = 0;
        fori (i, 1, p + 1) {
            ok |= bfs(i);
        }
    }

    par(cnt, 1, p + 1, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

