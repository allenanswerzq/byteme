//============================================================================
// Name        : r
// Date        : Wed Mar 20 11:05:37 CST 2019
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

int n;
void solve() {
    vs a(n);
    for (auto &t : a) {
        cin >> t;
    }
    // trace(a);
    vvi dp(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == n - 1) {
                dp[i][j] = 1;
                continue;
            }

            int u = i, r = j;
            while (u >= 0 && r < n && a[u][j] == a[i][r]) {
                --u, ++r;
            }

            int len = i - u;
            if (len >= dp[i - 1][j + 1] + 1) {
                dp[i][j] = dp[i - 1][j + 1] + 1;
            } else {
                dp[i][j] = len;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret = max(ret, dp[i][j]);
        }
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

