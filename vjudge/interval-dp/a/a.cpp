//============================================================================
// Name        : a
// Date        : Fri Apr  5 11:23:44 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case " << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

inline void amin(int& a, int b) {
    a = min(a, b);
}

const int maxn = 120;
int dp[maxn][maxn];
int rec(vi& a, int lo, int hi) {
    int& ret = dp[lo][hi];
    if (ret != -1) {
        return ret;
    }
    if (lo > hi) {
        return ret = 0;
    }
    if (lo == hi) {
        return ret = 1;
    }
    ret = 1 + rec(a, lo + 1, hi);
    for (int i = lo + 1; i <= hi; ++i) {
        if (a[lo] == a[i]) {
            amin(ret, rec(a, lo, i - 1) + rec(a, i + 1, hi));
        }
    }
    return ret;
}

void solve(int cs) {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mst(dp, -1);
    int ret = rec(a, 0, n - 1);
    jam(cs, ret);
}

void solve2(int cs) {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vvi dp(n + 1, vi(n + 1, 0));
    for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            dp[L][R] = dp[L + 1][R] + 1;
            for (int k = L + 1; k <= R; ++k) {
                if (a[L] == a[k]) {
                    amin(dp[L][R], dp[L + 1][k] + dp[k + 1][R]);
                }
            }
        }
    }
    trace(dp);
    jam(cs, dp[0][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        solve2(i);
    }
    return 0;
}

