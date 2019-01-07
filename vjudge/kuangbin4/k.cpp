// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <stack>
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

typedef struct Edge {
    int to, weight, next;
} Edge;

const int maxn = 30007;
const int maxm = 150007;

int n, m, k_edge;
int dist[maxn];
int visit[maxn];

// Use link list to represent a graph.
int head[maxn];
Edge gg[maxm];

// O(vlogv + e)

void dijkstra() {
    mst(dist, 0x3f);

    priority_queue<pii, vpii, greater<pii> > dq;
    dq.push({0, 1});
    dist[1] = 0;

    while (sz(dq)) {
        pii p = dq.top(); dq.pop();
        int d = p.first, u = p.second;

        // Why this could ever happen??? If the node we choose in min heap
        // whose distance is greater than global shortes path of itself,
        // then do nothing.
        //
        if (d > dist[u]) {
            continue;
        }

        for (int i = head[u]; i != -1; i = gg[i].next) {
            Edge e = gg[i];
            int v = e.to, w = e.weight;
            if (w && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                dq.push({dist[v], v});
            }
        }
    }

    output(dist[n]);
}

void spfa() {
    mst(dist, 0x3f);
    mst(visit, 0);

    // Here use a stack will pass, use deque will tle.
    stack<int> dq;
    dq.push(1);
    dist[1] = 0;
    visit[1] = 0;

    while (sz(dq)) {
        int u = dq.top(); dq.pop();
        visit[u] = 0;
        for (int i = head[u]; i != -1; i = gg[i].next) {
            Edge e = gg[i];
            int v = e.to, w = e.weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = 1;
                    dq.push(v);
                }
            }
        }
    }

    output(dist[n]);
}

void add_edge(int &u, int &v, int &w) {
    Edge e = {v, w, head[u]};
    gg[k_edge] = e;
    head[u] = k_edge++;
}

void solve() {
    k_edge = 0;
    mst(head, -1);
    scanf("%d %d", &n, &m);
    fori (i, 0, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    // spfa();
    dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
