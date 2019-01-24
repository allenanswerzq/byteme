// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
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

// Sloving difference constraints via shortest paths

typedef struct Edge {
    int u, v, w;
} Edge;

const int maxn = 1e3 + 7;
const int inf = 0x3f3f3f3f;

vector<Edge> gg[maxn];
int n, ml, md;
int que[maxn];
int dist[maxn];
int visit[maxn];
int cnt[maxn];

void add_edge(int u, int v, int w) {
    gg[u].pb({u, v, w});
}

bool spfa(int src, int n) {
    mst(visit, 0);
    mst(dist, 0x3f);

    int front = 0, rear = 0;
    que[rear++] = src;
    dist[src] = 0;
    visit[src] = 1;

    while (front != rear) {
        int u = que[front++];
        fori (i, 0, sz(gg[u])) {
            Edge edge = gg[u][i];
            int v = edge.v, w = edge.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = 1;
                    que[rear++] = v;
                    if (rear == maxn) rear = 0;
                    if (++cnt[v] > n) return 0;
                }
            }
        }
        visit[u] = 0;
        if (front == maxn) front = 0;
    }
    return 1;
}

void solve() {
    cin >> n >> ml >> md;
    fori (i, 0, ml) {
        int u, v, c; cin >> u >> v >> c;
        if (u > v) swap(u, v);
        add_edge(u, v, c);
    }

    fori (i, 0, md) {
        int u, v, c; cin >> u >> v >> c;
        if (u < v) swap(u, v);
        add_edge(u, v, -c);
    }

    bool ret = spfa(1, n);
    if (!ret) {
        // Cycle exists.
        output(-1);
    } else if (dist[n] == inf) {
        output(-2);
    } else {
        output(dist[n]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
