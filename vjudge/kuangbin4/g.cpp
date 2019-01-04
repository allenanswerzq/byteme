// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
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

const int maxn = 200;
int n;
int graph[maxn][maxn];
int visit[maxn], dist[maxn];

void spfa() {
    mst(visit, 0);
    mst(dist, 0x3f);

    deque<int> dq;
    dq.pb(1);
    visit[1] = 1;
    dist[1] = 0;

    while (sz(dq)) {
        int u = dq.front(); dq.pop_front();
        visit[u] = 0;
        fori (v, 1, n + 1) {
            int w = graph[u][v];
            if (v != u && w && w != -1 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = 1;
                    dq.pb(v);
                }
            }
        }
    }

    // par(dist, n + 1, 1);

    int ret = 0;
    fori (i, 1, n + 1) {
        ret = max(ret, dist[i]);
    }

    output(ret);

}

void dijkstra() {
    mst(visit, 0);
    mst(dist, 0x3f);

    priority_queue<pii, vpii, greater<pii> > dq;
    dq.push({0, 1});
    dist[1] = 0;

    while (sz(dq)) {
        int u = dq.top().second; dq.pop();
        fori (v, 1, n + 1) {
            int w = graph[u][v];
            if (v != u && w && w != -1 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                dq.push({dist[v], v});
            }
        }
    }

    // par(dist, n + 1, 1);

    int ret = 0;
    fori (i, 1, n + 1) {
        ret = max(ret, dist[i]);
    }

    output(ret);
}

void solve() {
    cin >> n;
    fori (i, 1, n + 1) {
        for (int j = 1; j < i; ++j) {
            string w; cin >> w;
            if (w == "x") {
                graph[i][j] = graph[j][i] = -1;
            } else {
                graph[i][j] = graph[j][i] = atoi(w.c_str());
            }
        }
    }

    // fori (i, 1, n + 1) {
    //     par(graph[i], n + 1, 1);
    // }

    spfa();
    // dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
