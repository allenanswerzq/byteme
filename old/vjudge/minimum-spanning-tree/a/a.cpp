//============================================================================
// Name        : a
// Date        : Tue Jan 22 09:56:39 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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

struct Edge {
    int u, v, w;
};

struct UF {
    vi e;
    UF(int n) : e(n + 1, -1) {}

    int find(int x) {
        if (e[x] < 0) return x;
        e[x] = find(e[x]);
        return e[x];
    }

    void join(int u, int v) {
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            e[t2] = t1;
        }
    }

    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};

const int maxn = (int) 1e4;
Edge edges[maxn];
int n, m;

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

void kruskal() {
    sort(edges, edges + m, cmp);

    int ret = 0;
    UF uf(n);
    fori (i, 0, m) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (!uf.same_set(u, v)) {
            uf.join(u, v);
            ret += w;
        }
    }
    output(ret);
}

void solve_mst_kruskal() {
    m = 0;
    fori (i, 0, n - 1) {
        char u; int k;
        cin >> u >> k;
        fori (j, 0, k) {
            char v; int w;
            cin >> v >> w;
            edges[m++] = {u - 'A', v - 'A', w};
        }
    }
    kruskal();
}

struct Node {
    int v, w;
    // Since the priority_queue needs a greater function to make a min heap.
    bool operator< (const Node& b) const {
        return w > b.w;
    }
};
vector<Node> gg[30];
bool visit[30];

void prim() {
    mst(visit, 0);

    priority_queue<Node> dq;
    dq.push({0, 0});
    int ret = 0;
    while (sz(dq)) {
        Node tt = dq.top(); dq.pop();
        int u = tt.v, w = tt.w;
        if (visit[u]) continue;
        ret += w;
        visit[u] = 1;
        fori (i, 0, sz(gg[u])) {
            int v = gg[u][i].v;;
            if (!visit[v]) {
                dq.push(gg[u][i]);
            }
        }
    }
    output(ret);
}

void solve_mst_prim() {
    fori (i, 0, 30) {
        gg[i].clear();
    }

    m = 0;
    fori (i, 0, n - 1) {
        char u; int k;
        cin >> u >> k;
        fori (j, 0, k) {
            char v; int w;
            cin >> v >> w;
            gg[u - 'A'].pb({v - 'A', w});
            gg[v - 'A'].pb({u - 'A', w});
        }
    }
    prim();
}

void test_less_than() {
    vector<Node> aa = {{1, 2}, {2, 1}};
    sort(all(aa));
    fora (a, aa) {
        cout << a.v << " " << a.w << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // test_less_than();

    while (cin >> n) {
        if (n == 0) break;
        // solve_mst_kruskal();
        solve_mst_prim();
    }
    return 0;
}

