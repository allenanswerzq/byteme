//============================================================================
// Name        : g
// Date        : Wed Jan 23 16:29:34 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
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

const int maxn = 520;

Point points[maxn];
double cost[maxn][maxn];
double dist[maxn];
double mst[maxn];
int s, n;

double euclid(Point& a, Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void prim() {
    fori (i, 2, n + 1) {
        dist[i] = cost[1][i];
    }

    dist[1] = -1;
    fori (i, 1, n) {
        double mi = 1000000;
        int u = -1;
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }
        mst[i] = mi;
        dist[u] = -1;
        fori (v, 1, n + 1) {
            if (dist[v] > -1 && dist[v] > cost[u][v]) {
                dist[v] = cost[u][v];
            }
        }
    }
    sort(mst + 1, mst + n);
    // par(mst, 0, n + 1, 1);
    output(mst[n - s]);
}

void solve() {
    cin >> s >> n;
    mst(points, 0);
    fori (i, 1, n + 1) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    mst(cost, 0);
    fori (i, 1, n + 1) fori (j, i + 1, n + 1) {
        cost[i][j] = cost[j][i] = euclid(points[i], points[j]);
    }

    // fori (i, 0, n) {
    //     par(cost[i], 0, n, 1);
    // }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(2); cout << fixed;

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

