//============================================================================
// Name        : u
// Date        : Wed Mar  6 16:50:29 CST 2019
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

const ll inf = (ll) 1e18 + 7;

vl pre, dp;

void rec(int i, vi& not_taken, ll score_so_far, int mask, int group) {
    // If we already have a group denoted by mask, what should we do
    // for the rest of rabbits?
    // For each rabbit, there are two choice here:
    //      1> do not include this into new group,
    //      2> include this into new group
    if (i == sz(not_taken)) {
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }

    rec(i + 1, not_taken, score_so_far, mask, group);
    rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}

void solve() {
    int n; cin >> n;
    vector<vl> a(n, vl(n));
    fori (i, 0, n) fori (j, 0, n) {
        cin >> a[i][j];
    }

    pre = vl(1 << n);
    fori (mask, 0, (1 << n)) {
        fori (i, 0, n) {
            if (mask & (1 << i)) {
                fori (j, i + 1, n) {
                    if (mask & (1 << j)) {
                        pre[mask] += a[i][j];
                    }
                }
            }
        }
    }

    dp = vl(1 << n, -inf);
    dp[0] = 0;
    fori (mask, 0, (1 << n)) {
        vi not_taken;
        fori (i, 0, n) {
            if (!(mask & (1 << i))) {
                not_taken.pb(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }
    output(dp[(1 << n) - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

