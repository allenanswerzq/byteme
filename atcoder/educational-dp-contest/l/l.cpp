//============================================================================
// Name        : l
// Date        : Wed Feb 20 21:45:48 CST 2019
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

const int maxn = 3007;
const ll inf = 1e18 + 7;

ll dp[maxn][maxn][2];
int aa[maxn];

ll rec(int l, int r, int who){
    if (dp[l][r][who] != -inf) {
        return dp[l][r][who];
    }

    if (l > r) {
        return 0;
    }

    if (who == 0){
        ll x = -inf;
        x = max(x, aa[l] + rec(l + 1, r, 1));
        x = max(x, aa[r] + rec(l, r - 1, 1));
        return dp[l][r][who] = x;
    } else {
        ll x = inf;
        x = min(x, -aa[l] + rec(l + 1, r, 0));
        x = min(x, -aa[r] + rec(l, r - 1, 0));
        return dp[l][r][who] = x;
    }
}

void solve() {
    int n; cin >> n;
    fori (i, 1, n + 1) {
        cin >> aa[i];
    }

    fori (i, 0, maxn) fori (j, 0, maxn) fori (k, 0, 2) {
        dp[i][j][k] = -inf;
    }

    output(rec(1, n, 0));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

