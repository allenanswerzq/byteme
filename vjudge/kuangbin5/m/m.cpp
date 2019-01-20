//============================================================================
// Name        : m
// Date        : Sun Jan 20 15:52:18 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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

struct Edge {
    int u, v;
};

struct Query {
    int u, v, op;
};

// Each root node denotes the largest power that also has smallest
// number for some edges that can send message between each other.
struct UF {
    vi e, power, index;
    UF(int n, vi& p, vi& idx) : e(n+1, -1), power(p), index(idx) {}

    int find(int x) {
        if (e[x] < 0) return x;
        return find(e[x]);
    }

    void join(int u, int v) {
        // Node u can send message to v
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            e[t1] = t2;
            if (power[t2] < power[t1]) {
                power[t2] = power[t1];
                index[t2] = index[t1];
            } else if (power[t1] == power[t2] && index[t2] > index[t1]) {
                index[t2] = index[t1];
            }
        }
    }

    int get_power(int u) {
        return power[u];
    }

    int get_index(int u) {
        return index[u];
    }
};

const int maxm = 20000 + 7;
const int maxq = 50000 + 7;
const int maxn = 10000 + 7;

Edge edges[maxm];
int visit[maxm];

Query queries[maxq];
int ret[maxq];

map<int, int> edge_idx[maxn];
int n;
void solve() {
    vi power(n + 1, 0), index(n + 1, 0);
    fori (i, 0, n) {
        cin >> power[i];
        index[i] = i;
        edge_idx[i].clear();
    }

    int m; cin >> m;
    mst(visit, 0);
    mst(edges, 0);
    fori (i, 0, m) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edge_idx[u][v] = i;
        edges[i] = {u, v};
        visit[i] = 0;
    }

    int q; cin >> q;
    mst(queries, 0);
    fori (i, 0, q) {
        string op;
        cin >> op;
        if (op == "query") {
            int u; cin >> u;
            queries[i] = {u, -1, 0};
        } else {
            int u, v; cin >> u >> v;
            if (u > v) swap(u, v);
            queries[i] = {u, v, 1};
            visit[edge_idx[u][v]] = 1;
        }
    }

    UF uf(n, power, index);
    // Reverse thinking, don't join egdes which be destroyed in the future.
    fori (i, 0, m) {
        if (visit[i] == 0) {
            uf.join(edges[i].u, edges[i].v);
        }
    }

    int k = 0;
    ford (i, q - 1, -1) {
        int u = queries[i].u, v = queries[i].v, op = queries[i].op;
        if (op == 0) {
            int root = uf.find(u);
            if (uf.get_power(root) > power[u]) {
                ret[k++] = uf.get_index(root);
            } else {
                ret[k++] = -1;
            }
        } else {
            // Now it's time to join destroyed edges.
            uf.join(u, v);
        }
    }

    ford (i, k - 1, -1) {
        cout << ret[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool first = 1;
    while (cin >> n) {
        if (first) first = 0;
        else cout << "\n";
        solve();
    }
    return 0;
}

