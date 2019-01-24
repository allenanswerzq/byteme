#include <bits/stdc++.h>
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

typedef struct Edge {
    int v, w;
} Edge;

const int maxn = 3 * (1e5 + 7);
const int inf = 0x3f3f3f3f;

// Link list to represent a graph.
vector<Edge> gg[maxn];

int dist[maxn];
int n, m, c, edge_cnt;

void dijkstra() {
    mst(dist, 0x3f);

    priority_queue<pii, vpii, greater<pii>> dq;
    dq.push({0, 1});
    dist[1] = 0;

    while (sz(dq)) {
        pii p = dq.top(); dq.pop();
        int d = p.first, u = p.second;
        if (d <= dist[u]) {
            fori (i, 0, sz(gg[u])) {
                int v = gg[u][i].v, w = gg[u][i].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    dq.push({dist[v], v});
                }
            }
        }
    }
}

void add_edge(int u, int v, int w) {
    gg[u].pb({v, w});
}

void solve(int tt) {
    cin >> n >> m >> c;

    fori (i, 1, 3 * n + 1) {
        gg[i].clear();
    }

    // Node(i) --> Node(N) --> Layer(i, i + 1) --> Layer(n, n + 1)
    // Each layer splited to two nodes here, one is in node, another one
    // is out node.
    fori (i, 1, n + 1) {
        int u; cin >> u;
        // Node i can enter into the layer u.
        add_edge(i, n + 2 * u - 1, 0);
        add_edge(n + 2 * u, i, 0);
    }

    fori (i, 1, n) {
        // Layer x's in node link to layer x + 1's out node.
        add_edge(n + 2 * i - 1, n + 2 * (i + 1), c);
        // Layer x + 1's in node link to layer x's out node.
        add_edge(n + 2 * (i + 1) - 1, n + 2 * i, c);
    }

    fori (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dijkstra();
    codejam(tt, (dist[n] == inf ? -1 : dist[n]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}
