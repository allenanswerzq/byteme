//============================================================================
// Name        : l
// Date        : Sun Jan 27 15:22:46 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
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
int n;

void prim() {
    fori (i, 1, n + 1) {
        if (i == 1) dist[i] = -1;
        else dist[i] = cost[1][i];
    }
    int ret = 0;
    fori (i, 1, n) {
        int u = -1, mi = numeric_limits<int>::max();
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }
        ret += dist[u];
        dist[u] = -1;
        fori (v, 1, n + 1) {
            dist[v] = min(dist[v], cost[u][v]);
        }
    }
    output(ret);
}

void solve() {
    mst(dist, 0x3f);
    int m = n * (n - 1) / 2;
    fori (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }

    // fori (i, 1, n + 1) {
    //     par(cost[i], 1, n + 1, 1);
    // }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

