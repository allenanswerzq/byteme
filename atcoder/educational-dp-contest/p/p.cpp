//============================================================================
// Name        : p
// Date        : Mon Mar  4 21:10:15 CST 2019
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

#define x first
#define y second

const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 7;

void mul(int& a, int b) {
    a = ((ll) a * b) % mod;
}

pii dp[maxn];
vi gg[maxn];

pii dfs(int u, int parent) {
    if (dp[u].x || dp[u].y) {
        return dp[u];
    }

    pii ret = {1, 1};
    fora (v, gg[u]) {
        if (v != parent) {
            pii t = dfs(v, u);
            // white black.
            mul(ret.x, t.y + t.x);
            mul(ret.y, t.x);
        }
    }
    return dp[u] = ret;
}

void solve() {
    int n; cin >> n;
    fori (i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        gg[x].pb(y);
        gg[y].pb(x);
    }

    dfs(1, -1);
    int ret = (dp[1].x + dp[1].y) % mod;
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

