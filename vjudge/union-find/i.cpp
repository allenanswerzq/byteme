//============================================================================
// Name        : i
// Date        : Thu Jan 17 14:09:56 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
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

struct UF {
    vi e, dx, dy;
    UF(int n) : e(n + 1, -1), dx(n + 1, 0), dy(n + 1, 0) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int root = find(e[x]);
        dx[x] += dx[e[x]];
        dy[x] += dy[e[x]];
        e[x] = root;
        return root;
    }

    void join(int u, int v, int len, char dir) {
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            int x, y;
            if (dir == 'N') {
                x = len, y = 0;
            } else if (dir == 'S') {
                x = -len, y = 0;
            } else if (dir == 'E') {
                x = 0, y = len;
            } else {
                x = 0, y = -len;
            }
            e[t2] = t1;
            dx[t2] = dx[u] - dx[v] + x;
            dy[t2] = dy[u] - dy[v] + y;
        }
    }

    int get(int u, int v) {
        int t1 = find(u), t2 = find(v);
        if (t1 == t2) {
            return abs(dx[u] - dx[v]) + abs(dy[u] - dy[v]);
        } else {
            return -1;
        }
    }

};

const int maxn = 4e4 + 7;
struct Farm {
    int u, v, len;
    char dir;
} farm[maxn];

struct Query {
    int u, v, step, idx;
} query[maxn];

bool cmp(Query a, Query b) {
    return a.step < b.step;
}

int n, m;
void solve() {
    UF uf(n);
    fori (i, 1, m + 1) {
        int u, v, len; char dir;
        cin >> u >> v >> len >> dir;
        farm[i] = {u, v, len, dir};
    }

    int q; cin >> q;
    fori (i, 1, q + 1) {
        int u, v, step, idx = i;
        cin >> u >> v >> step;
        query[i] = {u, v, step, idx};
    }

    sort(query + 1, query + 1 + q, cmp);

    int cur_step = 1;
    vi ret(q + 1, 0);
    fori (i, 1, q + 1) {
        int query_u = query[i].u;
        int query_v = query[i].v;
        int query_idx = query[i].idx;
        int query_step = query[i].step;
        while (cur_step <= m && cur_step <= query_step) {
            uf.join(farm[cur_step].u, farm[cur_step].v,
                    farm[cur_step].len, farm[cur_step].dir);
            ++cur_step;
        }
        // trace(query_u, query_v, cur_step, query_step);
        ret[query_idx] = uf.get(query_u, query_v);
    }

    fori (i, 1, q + 1) {
        output(ret[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        solve();
    }
    return 0;
}
