//============================================================================
// Name        : j
// Date        : Sat Jan 26 20:47:35 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <limits>
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

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//     cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//     const char* split = strchr(names + 1, ',');
//     cout.write(names, split - names) << ": " << arg << " |";
//     _f(split, args...);
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

struct Node {
    int x, y, step;
};

const int maxn = 120;
int cost[maxn][maxn];
int gg[maxn][maxn];
int dist[maxn];
bool visit[maxn][maxn];
int n, m, knode;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void prim() {
    fori (v, 1, knode + 1) {
        if (v == 1) dist[v] = -1;
        else dist[v] = cost[1][v];
    }

    int ret = 0;
    fori (i, 1, knode) {
        int u = -1, mi = numeric_limits<int>::max();
        fori (v, 1, knode + 1) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }
        ret += dist[u];
        dist[u] = -1;
        fori (v, 1, knode + 1) {
            dist[v] = min(dist[v], cost[u][v]);
        }
    }
    output(ret);
}

bool check(int nx, int ny) {
    return (0 <= nx && nx < n && 0 <= ny && ny < m);
}

void bfs(int ix, int iy) {
    mst(visit, 0);
    deque<Node> dq;
    dq.pb({ix, iy, 0});
    visit[ix][iy] = 1;
    int cnt = 0;
    while (sz(dq)) {
        Node nd = dq.front(); dq.pop_front();
        int x = nd.x, y = nd.y, step = nd.step;
        fori (i, 0, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && gg[nx][ny] >= 0 && !visit[nx][ny]) {
                Node nxt = {nx, ny, step + 1};
                visit[nx][ny] = 1;
                dq.pb(nxt);
                if (gg[nx][ny] > 0) {
                    int u = gg[ix][iy];
                    int v = gg[nx][ny];
                    cost[u][v] = nxt.step;
                    // trace(u, v, x, y, nx, ny, nxt.step, cost[u][v]);
                    if (++cnt == knode) return;
                }
            }
        }
    }
}

void solve() {
    cin >> m >> n >> ws;

    // trace(n, m);
    mst(gg, 0);
    knode = 0;
    fori (i, 0, n) {
        string ss; getline(cin, ss);
        // trace(ss, sz(ss));
        fori (j, 0, sz(ss)) {
            if (ss[j] == '#') gg[i][j] = -1;
            else if (ss[j] == ' ') gg[i][j] = 0;
            else gg[i][j] = ++knode;
        }
        fori (j, sz(ss), m) {
            gg[i][j] = 0;
        }
    }

    // fori (i, 0, n) {
    //     par(gg[i], 0, m, 1);
    // }

    mst(cost, 0);
    fori (i, 0, n) fori(j, 0, n) {
        if (gg[i][j] > 0) {
            bfs(i, j);
        }
    }

    // fori (i, 0, knode + 1) {
    //     par(cost[i], 0, knode + 1, 1);
    // }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

