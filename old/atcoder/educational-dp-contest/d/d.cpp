//============================================================================
// Name        : d
// Date        : Wed Feb 20 09:23:06 CST 2019
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

void amax(ll &a, ll b) {
    a = max(a, b);
}

void solve_one() {
// dp[i][v] the maximum value we can get if the last consideration is ith item
// and the weight of knapsack is `v`.
    int n, w; cin >> n >> w;
    vi vv(n + 1), ww(n + 1);
    fori (i, 1, n + 1) {
        cin >> ww[i] >> vv[i];
    }

    vector<vl> dp(n + 1, vl(w + 1, 0));
    fori (i, 1, n + 1) {
        fori (v, 0, w + 1) {
            amax(dp[i][v], dp[i - 1][v]);
            if (v - ww[i] >= 0) {
                amax(dp[i][v], dp[i - 1][v - ww[i]] + vv[i]);
            }
        }
    }
    output(dp[n][w]);
}

void solve() {
// dp[i] the maximum value of items with their sum weight is `i`
    int n, w;
    cin >> n >> w;
    vl dp(w + 1, 0);
    fori (i, 0, n) {
        ll weight, value;
        cin >> weight >> value;
        ford (j, w - weight, -1) {
            amax(dp[j + weight], dp[j] + value);
        }
    }

    ll ret = 0;
    fori (i, 0, w + 1) {
        ret = max(ret, dp[i]);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

