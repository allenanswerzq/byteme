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

// TODO (landcold7): probablity dp

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

    dp[cnt[1]][cnt[2]][cnt[3]] = 1;
    ford (c, n, -1) ford (b, n, -1) ford (a, n, -1) {
        int tot = (a + b + c);
        // trace(a, b, c);

        // eat 1
        if (a) {
            dp[a - 1][b][c] += dp[a][b][c] * a * 1.0 / tot;
        }

        // eat 2
        if (b) {
            dp[a + 1][b - 1][c] += dp[a][b][c] * b * 1.0 / tot;
        }

        // eat 3
        if (c) {
            dp[a][b + 1][c - 1] += dp[a][b][c] * c * 1.0 / tot;
        }
    }

    output(dp[0][0][0]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

