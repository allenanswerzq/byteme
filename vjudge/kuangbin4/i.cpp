// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
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
#define codejam(ix, v) cout << "Case " << (ix) << ": " << (v) << '\n'
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

const int maxn = 33;
int n, m, cnt, visit[maxn], counters[maxn];
map<string, int> mp;
double graph[maxn][maxn];
double dist[maxn];

bool spfa() {

    mst(visit, 0);
    mst(counters, 0);
    fori (i, 1, n + 1) {
        dist[i] = 0;
    }

    deque<int> dq;
    dq.pb(1);
    dist[1] = 1;
    visit[1] = 1;

    while (sz(dq)) {
        int u = dq.front(); dq.pop_front();
        visit[u] = 0;
        // trace(u, dist[u]);
        fori (v, 1, n + 1) {
            double w = graph[u][v];
            // trace(u, v, dist[u], w, dist[v]);
            if (dist[v] < dist[u] * w) {
                dist[v] = dist[u] * w;
                if (!visit[v]) {
                    visit[v] = 1;
                    dq.pb(v);
                    if (++counters[v] > n) {
                        return 1;
                    }
                }
            }
        }
    }

    return dist[1] > 1 ? 1 : 0;
}

void solve() {
    fori (i, 1, n + 1) {
        fori (j, 1, n + 1) {
            graph[i][j] = 0;
        }
    }

    mp.clear();
    fori (i, 1, n + 1) {
        string currency; cin >> currency;
        mp[currency] = i;
    }

    cin >> m;
    fori (i, 0, m) {
        string src, dst; double rate;
        cin >> src >> rate >> dst;
        int s = mp[src], t = mp[dst];
        graph[s][t] = rate;
    }

    // fori (i, 1, n + 1) {
    //     par(graph[i], n + 1, 1);
    // }

    if (spfa()) {
        codejam(cnt, "Yes");
    } else {
        codejam(cnt, "No");
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cnt = 0;
    while (cin >> n && n) {
        ++cnt;
        solve();
    }

    return 0;
}
