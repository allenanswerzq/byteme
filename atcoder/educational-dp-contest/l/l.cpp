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

// TODO(lancold7): game theory dp

const int maxn = 3007;
ll dp[maxn][maxn];

void solve() {
    int n; cin >> n;
    vi aa(n, 0);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    ford (i, n - 1, -1) {
        fori (j, i, n) {
            // trace(i, j);
            if (i == j) {
                dp[i][j] = aa[i];
            } else {
                dp[i][j] = max(aa[i] - dp[i+1][j], aa[j] - dp[i][j-1]);
            }
        }
    }
    output(dp[0][n-1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

