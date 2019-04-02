//============================================================================
// Name        : f
// Date        : Tue Apr  2 14:18:27 CST 2019
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
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vvi g;
vi color;
bool bipartite;

void dfs(int u, int c) {
    color[u] = c;
    for (auto v : g[u]) {
        if (color[v] == -1) {
            dfs(v, c ^ 1);
        } else {
            if (color[v] == color[u]) {
                bipartite = 0;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g = vvi(n);
    vpii e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
        e.pb({u, v});
    }

    bipartite = 1;
    color = vi(n, -1);
    dfs(0, 0);
    trace(color, e, g);

    if (!bipartite) {
        output("NO");
        return;
    }
    output("YES");
    for (int i = 0; i < m; ++i) {
        int x = e[i].x, y = e[i].y;
        cout << (color[x] < color[y]);
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

