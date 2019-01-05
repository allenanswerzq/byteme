// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
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

// TODO(landcold7): Still wrong answer, dont know why...

typedef struct Edge {
    int from, to, weight;
} Edge;

int n, m;
const int maxn = 1000010;
const int inf = (1 << 30);
vector<Edge> graph[maxn];
vector<Edge> reverse_graph[maxn];
int dist[maxn];

void dijkstra(vector<Edge> *graph) {

    fori (i, 1, n + 1) {
        dist[i] = inf;
    }

    // Min heap
    priority_queue<pii, vpii, greater<pii> > dq;
    dq.push({0, 1});
    dist[1] = 0;

    while (sz(dq)) {
        int u = dq.top().second; dq.pop();
        fori (i, 0, sz(graph[u])) {
            Edge e = graph[u][i];
            int v = e.to, w = e.weight;
            if (v != u && w && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                dq.push({dist[v], v});
            }
        }
    }

    // par(dist, n + 1, 1);
}

ll get_sum() {
    ll sum = 0;
    fori (i, 2, n + 1) {
        sum += dist[i];
    }
    return sum;
}

void solve() {
    fori (i, 1, maxn) {
        graph[i].clear();
        reverse_graph[i].clear();
    }
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    fori (i, 0, m) {
        int u, v, w;
        // cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb({u, v, w});
        reverse_graph[v].pb({v, u, w});
    }

    dijkstra(graph);

    ll ret = get_sum();

    dijkstra(reverse_graph);

    ret += get_sum();

    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}
