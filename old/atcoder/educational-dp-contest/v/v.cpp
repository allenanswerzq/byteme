//============================================================================
// Name        : v
// Date        : Thu Mar  7 18:25:14 CST 2019
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

vvi edges, kids, pref, suff;
vi down, up;
int n, mod;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (ll) a * b % mod;
}

// https://codeforces.com/blog/entry/64250?#comment-483299
void fast_down(int u) {
    if (down[u]) return;
    int ret = 1;
    fora (v, kids[u]) {
        fast_down(v);
        ret = mul(ret, 1 + down[v]);
    }
    down[u] = ret;

    int k = sz(kids[u]);
    pref[u] = vi(k + 1, 1);
    fori (i, 1, k + 1) {
        int v = kids[u][i - 1];
        pref[u][i] = mul(pref[u][i - 1], 1 + down[v]);
    }

    suff[u] = vi(k + 1, 1);
    ford (i, k - 1, -1) {
        int v = kids[u][i];
        suff[u][i] = mul(suff[u][i + 1], 1 + down[v]);
    }
}

void fast_up(int u) {
    if (u == 1) up[u] = 1;
    fori (i, 0, sz(kids[u])) {
        int v = kids[u][i];
        up[v] = up[u];
        up[v] = mul(up[v], pref[u][i]);
        up[v] = mul(up[v], suff[u][i + 1]);
        up[v] = add(up[v], 1);
        fast_up(v);
    }
}

// O(v + e)
// Get all directed kids for a ndoe u
void dfs(int u, int parent=-1) {
    fora (v, edges[u]) {
        if (v != parent) {
            kids[u].pb(v);
            dfs(v, u);
        }
    }
}

void solve_fast() {
    cin >> n >> mod;
    edges = vvi(n + 1);
    fori (i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    down = vi(n + 1);
    pref = vvi(n + 1);
    suff = vvi(n + 1);
    kids = vvi(n + 1);
    dfs(1);
    fast_down(1);

    up = vi(n + 1);
    fast_up(1);

    // trace(edges, kids, down, pref, suff, up);
    fori (i, 1, n + 1) {
        output(mul(down[i], up[i]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve_fast();
    return 0;
}

