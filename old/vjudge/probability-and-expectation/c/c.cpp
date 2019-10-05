//============================================================================
// Name        : c
// Date        : Wed Apr  3 15:06:13 CST 2019
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
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case " << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<double> dp;
void solve() {
    int n = (int)1e5 + 7;
    vvi a(n + 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                a[i].pb(j);
                if (j * j != i) {
                    a[i].pb(i / j);
                }
            }
        }
    }
    dp = vector<double>(n + 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = 1.0;
        for (auto d : a[i]) {
            if (d != i) {
                dp[i] += dp[d] + 1;
            }
        }
        dp[i] = dp[i] / (sz(a[i]) - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        int x; cin >> x;
        printf("Case %d: %.10lf\n", i, dp[x]);
    }
    return 0;
}
