//============================================================================
// Name        : t
// Date        : Wed Mar  6 11:22:36 CST 2019
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

// https://codeforces.com/blog/entry/64250?#comment-482526

const int mod = (int) 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    int n; string s;
    cin >> n >> s;

    vvi dp(n + 1, vi(n + 1));
    dp[1][1] = 1;
    fori (len, 2, n + 1) {
        vl pref(n + 1);
        fori (i, 1, len) {
            pref[i] = pref[i - 1] + dp[len - 1][i];
        }
        fori (j, 1, n + 1) {
            int lo, hi;
            if (s[len - 2] == '>') {
                lo = j, hi = len - 1;
            } else {
                lo = 1, hi = j - 1;
            }
            add(dp[len][j], (pref[hi] - pref[lo - 1] + mod) % mod);
            // fori (k, lo, hi + 1) {
            //     add(dp[len][j], dp[len - 1][k]);
            // }
        }
    }

    int ret = 0;
    fori (i, 1, n + 1) {
        add(ret, dp[n][i]);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

