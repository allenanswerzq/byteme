//============================================================================
// Name        : d
// Date        : Mon Apr  1 17:16:22 CST 2019
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
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
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

vi bits;
ll dp[25][12];

ll dfs(int p, int digit, bool small) {
    if (p == -1) {
        return 1;
    }
    if (!small && dp[p][digit] != -1) {
        return dp[p][digit];
    }
    ll ret = 0;
    int end = small ? bits[p] : 9;
    for (int i = 0; i <= end; ++i) {
        if (i == 9 && digit == 4) {
            continue;
        }
        ret += dfs(p - 1, i, small && (i == end));
    }
    if (!small) {
        dp[p][digit] = ret;
    }
    return ret;
}

ll solve(ll a) {
    bits.clear();
    mst(dp, -1);
    while (a) {
        bits.pb(a % 10);
        a /= 10;
    }
    return dfs(sz(bits) - 1, 0, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        ll a; cin >> a;
        output(a - solve(a) + 1);
    }
    return 0;
}

