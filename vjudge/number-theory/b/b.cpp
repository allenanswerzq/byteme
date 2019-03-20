//============================================================================
// Name        : b
// Date        : Wed Mar 20 16:23:34 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Graph {
    int L, R;
    vector<vector<int>> adj;
    Graph(int L, int R) : L(L), R(R), adj(L+R) { }
    void add_edge(int u, int v) {
        adj[u].push_back(v+L);
        adj[v+L].push_back(u);
    }
    int maximum_matching() {
        vector<int> level(L), mate(L+R, -1);

        function<bool(void)> levelize = [&]() { // BFS
            queue<int> Q;
            for (int u = 0; u < L; ++u) {
                level[u] = -1;
                if (mate[u] < 0) {
                    level[u] = 0;
                    Q.push(u);
                }
            }
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (int w: adj[u]) {
                    int v = mate[w];
                    if (v < 0) return true;
                    if (level[v] < 0) {
                        level[v] = level[u] + 1;
                        Q.push(v);
                    }
                }
            }
            return false;
        };
        function<bool(int)> augment = [&](int u) { // DFS
            for (int w: adj[u]) {
                int v = mate[w];
                if (v < 0 || (level[v] > level[u] && augment(v))) {
                    mate[u] = w;
                    mate[w] = u;
                    return true;
                }
            }
            return false;
        };
        int match = 0;
        while (levelize())
            for (int u = 0; u < L; ++u)
                if (mate[u] < 0 && augment(u))
                    ++match;
        return match;
    }
};

void solve(int cs) {
    int n; cin >> n;
    vi a(n);
    map<int, int> ha;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ha[a[i]] = i + 1;
    }

    Graph g(n, n);
    for (int i = 0; i < n; ++i) {
        int t = a[i];
        vi facts;
        for (int p = 2; p * p <= t; ++p) {
            if (t % p == 0) {
                facts.pb(p);
                while (t % p == 0) {
                    t /= p;
                }
            }
        }
        if (t > 1) {
            facts.pb(t);
        }
        for (auto f : facts) {
            int k = a[i] / f;
            if (ha.count(k)) {
                g.add_edge(i, ha[k] - 1);
                g.add_edge(ha[k] - 1, i);
            }
        }
    }
    int ret = n - g.maximum_matching() / 2;
    cout << "Case " << cs << ": " << ret << "\n";
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

