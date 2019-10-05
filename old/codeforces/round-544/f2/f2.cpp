//============================================================================
// Name        : f2
// Date        : Sun Mar 17 22:24:26 CST 2019
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

int n, m, d, cnt;
vi parent, color;
vvi g;
vpii ret;

void bfs(int u, int bad) {
    deque<int> dq;
    dq.pb(u);
    color[u] = cnt;
    while (sz(dq)) {
        int t = dq.front(); dq.pop_front();
        if (parent[t] != -1) {
            ret.pb({parent[t], t});
        }
        for (auto v : g[t]) {
            if (color[v] != -1 || v == bad) continue;
            color[v] = cnt;
            dq.pb(v);
            parent[v] = t;
        }
    }
    ++cnt;
}

void solve() {
    cin >> n >> m >> d;
    g = vvi(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    // Connected components
    cnt = 0;
    parent = color = vi(n, -1);
    for (int i = 1; i < n; ++i) {
        if (color[i] == -1) {
            bfs(i, 0);
        }
    }

    if (cnt > d || d > sz(g[0])) {
        output("NO");
        return;
    }

    sort(all(g[0]), [](int a, int b) {
        return color[a] < color[b];
    });

    for (int i = 0; i < sz(g[0]); ++i) {
        if (i == 0 || color[g[0][i]] != color[g[0][i - 1]]) {
            ret.pb({0, g[0][i]});
        }
    }

    d -= cnt;
    for (int i = 1; i < sz(g[0]); ++i) {
        if (d == 0) break;
        if (color[g[0][i]] == color[g[0][i - 1]]) {
            ret.pb({0, g[0][i]});
            --d;
        }
    }

    assert(d == 0);

    g = vvi(n);
    for (auto it : ret) {
        g[it.x].pb(it.y);
        g[it.y].pb(it.x);
    }
    ret.clear();
    parent = color = vi(n, -1);
    bfs(0, -1);

    assert(sz(ret) == n - 1);

    output("YES");
    for (auto it : ret) {
        cout << it.x + 1 << " " << it.y + 1 << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

