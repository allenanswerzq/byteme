//============================================================================
// Name        : g
// Date        : Wed Feb 20 14:06:02 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << "\n"
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

const int maxn = (int) 1e5 + 7;
vi gg[maxn];
int dp[maxn];

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    int ret = 0;
    fora (v, gg[u]) {
        ret = max(ret, dfs(v));
    }
    dp[u] = ret + 1;
    return dp[u];
}

void solve() {
    int n, m; cin >> n >> m;
    fori (i, 0, m) {
        int u, v; cin >> u >> v;
        gg[u].pb(v);
    }

    mst(dp, -1);
    fori (i, 1, n + 1) {
        if (dp[i] == -1) {
            dfs(i);
        }
    }
    // par(dp, 0, n + 1, 1);
    int ret = *max_element(dp + 1, dp + n + 1);
    output(ret - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

