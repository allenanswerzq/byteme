//============================================================================
// Name        : k
// Date        : Sun Jan 27 13:02:38 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <set>
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

const int maxn = 120;
int cost[maxn][maxn];
int dist[maxn];
int pi[maxn];
set<pii> mstt;
set<pii> gmstt;
int n, m, ret;

void prim(int src) {
    fori (i, 1, n + 1) {
        if (i == src) dist[i] = -1;
        else dist[i] = cost[src][i];
        pi[i] = src;
    }

    ret = 0;
    mstt.clear();
    fori (i, 1, n) {
        int u = -1, mi = numeric_limits<int>::max();
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }

        ret += dist[u];
        if (u != -1) {
            int t = u, w = pi[u];
            if (t > w) swap(t, w);
            mstt.insert({t, w});
        }

        dist[u] = -1;
        fori (v, 1, n + 1) {
            if (dist[v] > cost[u][v]) {
                dist[v] = cost[u][v];
                pi[v] = u;
            }
        }
    }
    // output(ret);
}

void solve() {
    cin >> n >> m;
    mst(cost, 0x3f);
    fori (j, 1, m + 1) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }

    // fori (i, 1, n + 1) {
    //     par(cost[i], 1, m + 1, 1);
    // }

    bool ok = 1;
    gmstt.clear();
    fori (i, 1, n + 1) {
        // trace(i);
        prim(i);
        if (i > 1) {
            vpii gmst(all(gmstt));
            fori (j, 0, sz(gmst)) {
                pii p = gmst[j];
                if (!mstt.count(p)) {
                    ok = 0;
                    break;
                }
            }
        }
        // fora (gmst, gmstt) {
        //     trace(gmst.first, gmst.second);
        // }
        // fora (mst, mstt) {
        //     trace(mst.first, mst.second);
        // }
        gmstt = mstt;
    }

    if (ok) {
        output(ret);
    } else {
        output("Not Unique!");
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

