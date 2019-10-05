//============================================================================
// Name        : m
// Date        : Thu Feb 21 10:19:17 CST 2019
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

const int mod = (int) 1e9 + 7;

void add(ll &a, ll b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(ll &a, ll b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vi aa(n + 1);
    fori (i, 1, n + 1) {
        cin >> aa[i];
    }

    vector<vl> dp(n + 1, vl(k + 1, 0));
    // dp[i][j]: the number of ways such that there are j candies for i childs.
    dp[0][0] = 1;
    fori (i, 1, n + 1) {
        // Compute prefix sum
        vl sum(k + 2, 0);
        fori (j, 1, k + 2) {
            sum[j] = (sum[j - 1] % mod + dp[i - 1][j - 1] % mod) % mod;
        }

        fori (j, 0, k + 1) {
            // dp[i][j] <- dp[i - 1][j - aa[i] + aa[i]]
            // dp[i][j] <- dp[i - 1][j - aa[i] - 1 + (aa[i] - 1)]

            ll pre = sum[j + 1];
            if (j - aa[i] >= 0) {
                sub(pre, sum[j - aa[i]]);
            }
            add(dp[i][j], pre);

            // Navie way of computing
            // fori (h, 0, aa[i] + 1) {
            //     if (j - h >= 0) {
            //         add(dp[i][j], dp[i - 1][j - h]);
            //     }
            // }
        }
    }
    // trace(dp);
    output(dp[n][k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

