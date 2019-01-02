// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
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

const int maxn = 1004;
int edges[maxn][maxn];
int n, m, cnt, dist[maxn], visit[maxn];

void dijkstra(int src) {

    fori (i, 1, n + 1) {
        dist[i] = edges[1][i];
    }

    visit[src] = cnt;

    while (1) {
        int u = -1, mx = 0;
        fori (i, 1, n + 1) {
            if (visit[i] != cnt && dist[i] > mx) {
                mx = dist[i], u = i;
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = cnt;
        fori (v, 1, n + 1) {
            int w = edges[u][v];
            if (visit[v] != cnt && w) {
                dist[v] = max(dist[v], min(dist[u], w));
            }
        }
    }

    // par(dist, n + 1, 1);

    cout << "Scenario #" << cnt << ":" << '\n';
    cout << dist[n] << "\n\n";
}

void solve() {
    cin >> n >> m;
    mst(edges, 0);
    fori (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u][v] = edges[v][u] = w;
    }
    dijkstra(1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cnt = 0;
    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        ++cnt;
        solve();
    }
    return 0;
}
