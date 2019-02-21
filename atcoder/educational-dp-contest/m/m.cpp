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
    if (a <= mod) {
        a += mod;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    // dp[i]: the number of ways such that used `i` candies so far.
    vl dp(k + 1);
    dp[0] = 1;
    fori (child, 0, n) {
        int a; cin >> a;
        vl fake(k + 1);
        ford (used, k, -1) {
            int ways = dp[used];
            int lo = used + 1, hi = used + min(a, k - used);
            if (lo <= hi) {
                add(fake[lo], ways);
                if (hi + 1 <= k) {
                    sub(fake[hi + 1], ways);
                }
            }
            // fori (i, lo, hi + 1) {
            //     add(dp[i], ways);
            // }
        }
        ll prefix_sum = 0;
        fori (i, 0, k + 1) {
            add(prefix_sum, fake[i]);
            add(dp[i], prefix_sum);
        }
    }
    output(dp[k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

