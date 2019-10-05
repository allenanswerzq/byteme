//============================================================================
// Name        : j
// Date        : Wed Feb 20 15:48:43 CST 2019
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

// https://math.stackexchange.com/questions/2368304/how-do-you-calculate-the-expected-value-of-geometric-distribution-without-diffre
// https://codeforces.com/blog/entry/64250?

const int maxn = 307;
// dp[i][j][k]
double dp[maxn][maxn][maxn];

void solve() {
    int n; cin >> n;
    vi cnt(4, 0);
    fori (i, 0, n) {
        int x; cin >> x;
        ++cnt[x];
    }

    dp[0][0][0] = 0;
    fori (c, 0, n + 1) fori (b, 0, n + 1) fori (a, 0, n + 1) {
        if (!a && !b && !c) continue;
        int x = (a + b + c);
        // trace(a, b, c);

        double p = 1.0 * n / x;
        // eat 1
        if (a) {
            dp[a][b][c] += dp[a - 1][b][c] * a * 1.0 / x;
        }

        // eat 2
        if (b) {
            dp[a][b][c] += dp[a + 1][b - 1][c] * b * 1.0 / x;
        }

        // eat 3
        if (c) {
            dp[a][b][c] += dp[a][b + 1][c - 1] * c * 1.0 / x;
        }

        dp[a][b][c] += p;
    }

    output(dp[cnt[1]][cnt[2]][cnt[3]]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(14);
    solve();
    return 0;
}

