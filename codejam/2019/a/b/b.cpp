//============================================================================
// Name        : b
// Date        : Sun Mar 24 13:33:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Node {
    int x, y, h;
};

int r, c;
int bfs(vs& a, int i, int j) {
    deque<Node> dq;
    dq.pb({i, j, 0});
    vvi visit(r, vi(c));
    visit[i][j] = 1;
    vpii dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (sz(dq)) {
        auto tp = dq.front(); dq.pop_front();
        if (a[tp.x][tp.y] == '1') {
            return tp.h;
        }
        for (auto dir : dirs) {
            int x = tp.x + dir.x;
            int y = tp.y + dir.y;
            int h = tp.h;
            if (0 <= x && x < r && 0 <= y && y < c && !visit[x][y]) {
                visit[x][y] = 1;
                dq.pb({x, y, h + 1});
            }
        }
    }
    return -1;
}

int time(vs& a) {
    int mx = 0;
    vvi d(r, vi(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == '1') {
                d[i][j] = 0;
            } else {
                d[i][j] = bfs(a, i, j);
            }
            mx = max(mx, d[i][j]);
        }
    }
    // trace(d);
    return mx;
}

const int inf = (int)1e9 + 7;

void solve(int cs) {
    cin >> r >> c;
    vs a(r);
    for (auto& t : a) {
        cin >> t;
    }

    // trace(a, time(a));
    int ret = inf;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            vs b = a;
            if (b[i][j] == '0') {
                b[i][j] = '1';
                // trace(a, b);
                ret = min(ret, time(b));
            }
        }
    }
    jam(cs, (ret == inf ? 0 : ret));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}

