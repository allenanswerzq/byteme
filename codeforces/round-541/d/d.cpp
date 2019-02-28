//============================================================================
// Name        : d
// Date        : Wed Feb 27 15:34:22 CST 2019
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

double tick() {
    static clock_t oldtick;
    clock_t newtick = clock();
    double diff = 1.0 * (newtick - oldtick) / CLOCKS_PER_SEC;
    oldtick = newtick;
    return diff;
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return -e[find(x)];
    }

    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
    }
};


vector<int> ret;
vector<set<int>> tree;

vector<int> topologicalSort(vector<set<int>>& g) {
    int n = sz(g);
    vector<int> deg(n);
    for (int u = 0; u < n; ++u)
        for (int v : g[u]) {
            ++deg[v];
        }

    vector<int> stack;
    for (int u = 0; u < n; ++u)
        if (!deg[u]) {
            stack.push_back(u);
            ret[u] = 1;
        }

    vector<int> order;
    while (!stack.empty()) {
        int u = stack.back(); stack.pop_back();
        order.push_back(u);
        for (int v : g[u]) {
            ret[v] = max(ret[v], ret[u] + 1);
            if (!--deg[v]) {
                stack.push_back(v);
            }
        }
    }

    return sz(order) == n ? order : vector<int>();
}


void solve() {
    int n, m;
    cin >> n >> m;
    vs aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    UF uf(n + m);
    fori (i, 0, n) fori (j, 0, m) {
        if (aa[i][j] == '=') {
            uf.join(i, j + n);
        }
    }

    trace(aa);

    tree = vector<set<int>>(n + m);
    fori (i, 0, n) fori (j, 0, m) {
        int u = uf.find(i);
        int v = uf.find(j + n);
        if (aa[i][j] == '>') {
            tree[v].insert(u);
        } else if (aa[i][j] == '<') {
            tree[u].insert(v);
        } else {
            // Do nothing.
        }
    }

    trace(tree);

    ret = vi(n + m);
    vi order = topologicalSort(tree);
    if (sz(order) == 0) {
        output("No");
        return;
    }

    trace(ret, order);

    output("Yes");
    fori (i, 0, n) {
        cout << ret[uf.find(i)] << (i < n - 1 ? " " : "\n");
    }

    fori (i, 0, m) {
        cout << ret[uf.find(i + n)] << (i < m - 1 ? " " : "\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;
    solve();
    return 0;
}

