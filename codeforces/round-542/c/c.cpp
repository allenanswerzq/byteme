//============================================================================
// Name        : c
// Date        : Fri Mar  1 11:24:48 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int inf = (int)1e9 + 7;

#define x first
#define y second

int n;
vs gg;
pii ss, ee;

void bfs(pii u, vpii& ret) {
    vector<vb> visit(n + 1, vb(n + 1));
    vpii dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    deque<pii> dq;
    dq.pb(u);
    visit[u.x][u.y] = 1;
    while (sz(dq)) {
        auto tp = dq.front(); dq.pop_front();
        assert(sz(dq) <= 60 * 60);
        ret.pb(tp);
        int x = tp.x, y = tp.y;
        trace(x, y);
        for (auto dir : dirs) {
            int nx = x + dir.x;
            int ny = y + dir.y;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n &&
                !visit[nx][ny] && gg[nx][ny] == '0') {
                dq.pb({nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }
}

void dfs(pii u, vpii& ret, vector<vb>& visit) {
    if (visit[u.x][u.y]) {
        return;
    }
    visit[u.x][u.y] = 1;
    ret.pb(u);
    vpii dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    fora (dir, dirs) {
        int x = u.x + dir.x;
        int y = u.y + dir.y;
        if (1 <= x && x <= n && 1 <= y && y <= n &&
            !visit[x][y] && gg[x][y] == '0') {
            dfs({x, y}, ret, visit);
        }
    }
}

void solve() {
    cin >> n;
    cin >> ss.x >> ss.y;
    cin >> ee.x >> ee.y;

    gg = vs(n + 1);
    fori (i, 1, n + 1) {
        string x; cin >> x;
        x = "$" + x;
        gg[i] = x;
    }

    vpii aa, bb;
    vector<vb> visit(n + 1, vb(n + 1));
    dfs(ss, aa, visit);
    visit.resize(n + 1, vb(n + 1));
    dfs(ee, bb, visit);

    // trace(gg, aa, bb);

    int ret = inf;
    fora (a, aa) fora (b, bb) {
        ret = min(ret, (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    output(ret == inf ? 0 : ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

