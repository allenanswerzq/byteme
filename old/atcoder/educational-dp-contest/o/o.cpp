//============================================================================
// Name        : o
// Date        : Mon Mar  4 16:55:29 CST 2019
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

const int mod = (int)1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    int n; cin >> n;
    vvi aa(n, vi(n));
    fori (i, 0, n) fori (j, 0, n) {
        cin >> aa[i][j];
    }

    // dp[i][mask] += dp[i-1][mask - (1 << j)]
    vi dp(1 << n);
    dp[0] = 1;
    fori (mask, 0, (1 << n) - 1) {
        int a = __builtin_popcount(mask);
        fori (b, 0, n) {
            if (aa[a][b] && !(mask & (1 << b))) {
                int m = mask ^ (1 << b);
                add(dp[m], dp[mask]);
            }
        }
    }
    output(dp[(1 << n) - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

