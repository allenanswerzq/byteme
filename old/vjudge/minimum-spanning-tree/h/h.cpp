//============================================================================
// Name        : h
// Date        : Sat Jan 26 16:49:08 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
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

struct Point {
    int x, y;
};
const int maxn = 1000;
double cost[maxn][maxn];
double dist[maxn];
int pi[maxn];
Point towns[maxn];
set<pii> st;
int n, m;

double euclid(Point& a, Point& b) {
    double ret = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(ret);
};

void prim() {
    fori (i, 2, n + 1) {
        dist[i] = cost[1][i];
        pi[i] = 1;
    }

    dist[1] = -1;
    fori (i, 1, n) {
        int u = -1; double mi = 10000000;
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }

        if (u != 1) {
            int t = u, w = pi[t];
            if (t > w) swap(t, w);
            if (!st.count({t, w})) {
                cout << t << " " << w << "\n";
            }
        }

        dist[u] = -1;
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && cost[u][v] < dist[v]) {
                dist[v] = cost[u][v];
                pi[v] = u;
            }
        }
    }
}

void solve() {
    cin >> n;

    mst(towns, 0);
    fori (i, 1, n + 1) {
        int x, y;
        cin >> x >> y;
        towns[i] = {x, y};
    }

    mst(cost, 0);
    fori (i, 1, n + 1) {
        fori (j, i + 1, n + 1) {
            cost[i][j] = cost[j][i] = euclid(towns[i], towns[j]);
        }
    }

    cin >> m;
    fori (i, 0, m) {
        int u, v;
        cin >> u >> v;
        cost[v][u] = cost[u][v] = 0;
        if (u > v) swap(u, v);
        st.insert({u, v});
    }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}

