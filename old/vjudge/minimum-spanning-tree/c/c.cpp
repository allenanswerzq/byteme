//============================================================================
// Name        : c
// Date        : Tue Jan 22 15:07:19 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <set>
#include <cmath>
#include <vector>
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
    double x, y, z, r;
};

double euclid(Point a, Point b) {
    double ret = (a.x - b.x) * (a.x - b.x) +
             (a.y - b.y) * (a.y - b.y) +
             (a.z - b.z) * (a.z - b.z);
    return max(sqrt(ret) - a.r - b.r, (double)0.0);
}

const int maxn = 120;
vector<Point> points;
double gg[maxn][maxn];
int visit[maxn];
int n;

const double eps = 1e-7;
struct Node {
    double w; int u;
    bool operator< (const Node& b) const {
        return w + eps < b.w;
    }
};

void prim() {
    mst(visit, 0);
    multiset<Node> dq;
    dq.insert({0, 1});

    double ret = 0;
    while (sz(dq)) {
        Node p = *dq.begin(); dq.erase(dq.begin());
        double w = p.w; int u = p.u;
        if (visit[u]) continue;
        visit[u] = 1;
        ret += w;
        fori (v, 0, n) {
            if (!visit[v]) {
                dq.insert({gg[u][v], v});
            }
        }
    }
    output(ret);
}

void solve() {
    points.clear();
    fori (i, 0, n) {
        double x, y, z, r;
        cin >> x >> y >> z >> r;
        points.pb({x, y, z, r});
    }

    mst(gg, 0);
    fori (i, 0, n) fori (j, i + 1, n) {
        gg[i][j] = gg[j][i] = euclid(points[i], points[j]);
    }

    // fori (i, 0, n) {
    //     par(gg[i], 0, n, 1);
    // }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(3);
    cout << fixed;

    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    return 0;
}

