//============================================================================
// Name        : i
// Date        : Wed Feb 20 14:56:10 CST 2019
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

void solve() {
    int n; cin >> n;
    // dp[i]: the probability of having i heads so far.
    vector<double> dp(n + 1, 0);
    dp[0] = 1;
    fori (i, 0, n) {
        double p; cin >> p;
        ford (j, i + 1, -1) {
            dp[j] = (j == 0 ? 0 : dp[j - 1] * p) + dp[j] * (1 - p);
        }
    }

    double ret = 0;
    fori (i, 0, n + 1) {
        if (i > n - i) {
            ret += dp[i];
        }
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    cin.tie(0);
    solve();
    return 0;
}

