//============================================================================
// Name        : div1d
// Date        : Wed Mar 13 10:40:31 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define first x
#define second y
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

struct UF {
    vi e;
    UF(int n) : e(n + 1, -1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return -e[find(x)];
    }

    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return 0;
        }
        if (e[a] > e[b]) {
            swap(a, b);
        }
        e[a] += e[b];
        e[b] = a;
        return 1;
    }
};

struct Edge {
    int u, v, w, id;
    Edge(int u, int v, int w, int id)
        : u(u), v(v), w(w), id(id) {}
    // friend debugstream& operator << (debugstream& os, Edge& e);
};

// debugstream& operator << (debugstream& os, Edge& e) {
//     os << "Edge(" << e.u << " " << e.v << " "
//        << e.w << " " << e.id << ")";
//     return os;
// }

const int maxn = (int)2e5 + 7;
vector<int> g[maxn];
int cost[maxn];

int timer = 0;
vector<Edge> e;
void dfs(int u, int p) {
    for (int i = 0; i < sz(g[u]); ++i) {
        if (g[u][i] == p) {
        // Remove parent node.
            g[u].erase(g[u].begin() + i);
        }
    }

    int l = timer;
    if (g[u].empty()) {
        ++timer;
    }

    for (auto& v : g[u]) {
        dfs(v, u);
    }

    int r = timer;
    e.emplace_back(l, r, cost[u], u);
}


void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 1);
    sort(all(e), [&](Edge& a, Edge& b) {
        return a.w < b.w;
    });

    UF uf(timer);
    vi can;
    ll ret = 0;
    int l = 0;
    while (l < sz(e)) {
        int r = l;
        while (r < sz(e) && e[l].w == e[r].w) {
            ++r;
        }

        for (int i = l; i < r; ++i) {
            if (uf.find(e[i].u) != uf.find(e[i].v)) {
                can.pb(e[i].id);
            }
        }

        for (int i = l; i < r; ++i) {
            if (uf.join(e[i].u, e[i].v)) {
                ret += e[i].w;
            }
        }
        l = r;
    }
    sort(all(can));
    cout << ret << " " << sz(can) << "\n";
    par(can, 0, sz(can), 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

