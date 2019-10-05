//============================================================================
// Name        : s
// Date        : Tue Mar  5 16:14:07 CST 2019
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

const int mod = (int) 1e9 + 7;

// Digit dp problem

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    string k; int d;
    cin >> k >> d;

    int n = sz(k);
    vvi dp(d, vi(2));
    dp[0][0] = 1;
    fori (i, 0, n) {
        vvi new_dp(d, vi(2));
        fori (sum, 0, d) {
            for (bool sm_already : {false, true}) {
                for (int digit = 0; digit < 10; ++digit) {
                    if (digit > k[i] - '0' && !sm_already) {
                        break;
                    }
                    bool small = sm_already || (digit < k[i] - '0');
                    // trace(sum, i, digit, sm_already, small);
                    add(new_dp[(sum + digit) % d][small], dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    int ret = (dp[0][0] + dp[0][1] - 1 + mod) % mod;
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

