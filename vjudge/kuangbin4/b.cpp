// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
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
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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

// double tick() {
//     static clock_t old;
//     clock_t now = clock();
//     double diff = 1.0 * (now - old);
//     diff /= CLOCKS_PER_SEC;
//     old = now;
//     return diff;
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
typedef pair<int, float> pif;


const int maxn = 220;
int n, cnt;
float edges[maxn][maxn], dist[maxn];
vpii points;

float calc(pii x, pii y) {
    int r = (x.first - y.first) * (x.first - y.first) +
            (x.second - y.second) * (x.second - y.second);
    return sqrt(r);
}

void compute_weight() {

    fori (i, 0, n) {
        fori (j, i + 1, n) {
            edges[i][j] = calc(points[i], points[j]);
            edges[j][i] = edges[i][j];
            // trace(edges[i][j], edges[j][i]);
        }
    }
}

void dijkstra(int src) {

    fori (i, 0, n) {
        dist[i] = 1e10;
    }

    // Min heap
    priority_queue<pif, vector<pif>, greater<pif> > dq;
    dq.push({src, 0});
    dist[src] = 0;

    while (sz(dq)) {
        pif cur = dq.top(); dq.pop();
        int u = cur.first;
        fori (i, 0, n) {
            float w = edges[u][i];
            if (i != u && dist[i] > max(dist[u], w)) {
                dist[i] = max(dist[u], w);
                dq.push({i, dist[i]});
            }
        }
    }

    // par(dist, n, 1);

    cout << "Scenario #" << cnt << '\n';
    cout << "Frog Distance = " << dist[1] << '\n';
    cout << '\n';

}

void solve() {
    points.clear();
    fori (i, 0, n) {
        int x, y; cin >> x >> y;
        points.pb({x, y});
    }

    compute_weight();

    // fori (i, 0, n) {
    //     par(edges[i], n, 1);
    // }

    dijkstra(0);
}

void test() {
    using pif = pair<int, float>;
    vector<pif> tt = {{0, 0.4}, {1, 0.2}, {0, 0.5}};
    sort(all(tt), greater<pif>());
    fora (t, tt) {
        trace(t.first, t.second);
    }
}

int main() {
    cnt = 0;
    cout.precision(3);
    cout << fixed;
    while (cin >> n && n) {
        ++cnt;
        solve();
    }
    return 0;
}

