//============================================================================
// Name        : m
// Date        : Sun Jan 27 15:35:11 CST 2019
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

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

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

double eculid(Point& a, Point& b) {
    double ret = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    return sqrt(ret);
}

const int maxn = 120;
double cost[maxn][maxn];
double dist[maxn];
Point points[maxn];
int n;

void prim() {
    fori (i, 0, n) {
        if (i == 0) dist[i] = -1;
        else dist[i] = cost[0][i];
    }
    double ret = 0;
    bool ok = 1;
    fori (i, 0, n - 1) {
        int u = -1; double mi = 1000000000;
        fori (v, 0, n) {
            if (dist[v] > -1 && dist[v] < mi) {
                mi = dist[v], u = v;
            }
        }
        if (u == -1) {
            ok = 0;
            break;
        }
        ret += dist[u];
        dist[u] = -1;
        fori (v, 0, n) {
            dist[v] = min(dist[v], cost[u][v]);
        }
    }
    if (ok) output(ret * 100);
    else output("oh!");
}

void solve() {
    cin >> n;
    fori (i, 0, n) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    fori (i, 0, n) fori (j, 0, n) {
        if (i == j) cost[i][j] = 0;
        else cost[i][j] = 1000000000;
    }

    fori (i, 0, n) fori (j, i + 1, n) {
        double d = eculid(points[i], points[j]);
        if (10.0 <= d && d < 1000.0) {
            cost[i][j] = cost[j][i] = d;
        }
    }

    // fori (i, 0, n) {
    //     par(cost[i], 0, n, 1);
    // }

    prim();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(1);
    cout << fixed;

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

