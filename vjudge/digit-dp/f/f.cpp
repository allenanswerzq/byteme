//============================================================================
// Name        : f
// Date        : Tue Apr  2 16:30:01 CST 2019
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
ll dp[25][25][2000];
ll dfs(int p, int pivot, int sum, bool small) {
    if (p == -1) {
    // If this number is a balance number, then the sum shoule be 0
    // after we processed from right to most left position.
        return sum == 0;
    }
    if (sum < 0) {
        return 0;
    }
    if (!small && dp[p][pivot][sum] != -1) {
        return dp[p][pivot][sum];
    }
    ll ret = 0;
    int end = small ? bits[p] : 9;
    for (int i = 0; i <= end; ++i) {
        int new_sum = sum + i * (p - pivot);
        ret += dfs(p - 1, pivot, new_sum, small && (i == end));
    }
    if (!small) {
        dp[p][pivot][sum] = ret;
    }
    return ret;
}

ll solve(ll a) {
    bits.clear();
    while (a) {
        bits.pb(a % 10);
        a /= 10;
    }
    ll ret = 0;
    for (int i = 0; i < sz(bits); ++i) {
        ret += dfs(sz(bits) - 1, i, 0, 1);
    }
    return (ret - (sz(bits) - 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mst(dp, -1);
    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        ll l, r;
        cin >> l >> r;
        output(solve(r) - solve(l - 1));
    }
    return 0;
}

