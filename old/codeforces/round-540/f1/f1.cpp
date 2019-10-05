//============================================================================
// Name        : f1
// Date        : Tue Feb 26 17:18:41 CST 2019
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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n, cnt, red, blue;
vi cols;
vvi tree;

pii dfs(int u, int parent = -1) {
    int r = (cols[u] == 1);
    int b = (cols[u] == 2);
    fora (v, tree[u]) {
        if (v != parent) {
            pii sub = dfs(v, u);
            // If current subtree has `all` red colors, it means the component
            // has only blue colors.
            cnt += (sub.first == red && sub.second == 0);
            cnt += (sub.first == 0 && sub.second == blue);
            r += sub.first;
            b += sub.second;
        }
    }
    return {r, b};
}

void solve() {
    cin >> n;
    cols = vi(n + 1);
    fori (i, 1, n + 1) {
        cin >> cols[i];
        red += (cols[i] == 1);
        blue += (cols[i] == 2);
    }

    tree = vvi(n + 1);
    fori (i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    // trace(cols, tree);

    cnt = 0;
    dfs(1);
    output(cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

