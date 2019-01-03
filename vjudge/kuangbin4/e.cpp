// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
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

int n, m, s; double v;

typedef struct Operation {
    int to;
    double rate, commission;
    Operation(int to, double r, double c)
        : to(to), rate(r), commission(c) {}
} Operation;

const int maxn = 120;
vector<Operation> ops[maxn];
double dist[maxn];
int counters[maxn];
// Mark whether a node in queue.
int visit[maxn];

// Shortest path fater algorithm.
bool spfa() {
    mst(visit, 0);
    mst(counters, 0);
    deque<int> dq;
    dq.pb(s);
    dist[s] = v;
    counters[s] = 1;
    visit[s] = 1;
    while (sz(dq)) {
        int u = dq.front(); dq.pop_front();
        // Poped from queue.
        visit[u] = 0;
        fori (i, 0, sz(ops[u])) {
            Operation op = ops[u][i];
            // If this u to v exchange can make money increases.
            double new_momey = (dist[u] - op.commission) * op.rate;
            if (new_momey > dist[op.to]) {
                dist[op.to] = new_momey;
                if (!visit[op.to]) {
                    dq.pb(op.to);
                    // If there is a money increasing cycle.
                    if (++counters[op.to] > n) {
                        return 1;
                    }
                }
            }
        }
    }

    return dist[s] > v ? 1 : 0;
}

void solve() {
    cin >> n >> m >> s >> v;
    fori (i, 0, m) {
        int u, v; double rate_u2v, commission_u2v, rate_v2u, commission_v2u;
        cin >> u >> v
            >> rate_u2v >> commission_u2v
            >> rate_v2u >> commission_v2u;
        ops[u].pb(Operation(v, rate_u2v, commission_u2v));
        ops[v].pb(Operation(u, rate_v2u, commission_v2u));
    }
    if (spfa()) {
        output("YES");
    } else {
        output("NO");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
