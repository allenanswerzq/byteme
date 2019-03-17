//============================================================================
// Name        : f1
// Date        : Fri Mar 15 15:51:28 CST 2019
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

const int maxn = (int)2e5 + 7;
vi g[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vi deg(n + 1);
    int mg = 0, ig = 0;
    fori (i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
        if (deg[u] > mg) {
            mg = deg[u];
            ig = u;
        }
        if (deg[v] > mg) {
            mg = deg[v];
            ig = v;
        }
    }
    // trace(mg, ig, deg);

    vi visit(n + 1);
    visit[ig] = 1;
    vpii ret;
    for (auto &v : g[ig]) {
        visit[v] = 1;
        ret.pb({ig, v});
    }

    for (int i = 1; i < n + 1; ++i) {
        if (!visit[i]) {
            for (auto &v : g[i]) {
                if (visit[v]) {
                    ret.pb({i, v});
                    break;
                }
            }
        }
    }
    // trace(n, sz(ret));
    // assert(sz(ret) == n - 1);
    for (auto p : ret) {
        cout << p.x << " " << p.y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

