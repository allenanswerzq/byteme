//============================================================================
// Name        : e
// Date        : Mon Apr  1 19:41:19 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <cstring>
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

// Ref: https://www.luogu.org/blog/virus2017/shuweidp:

vi bits;
ll dp[40][40][40];

ll dfs(int p, int cnt_zero, int cnt_one, bool zero, bool small) {
    if (p == -1) {
        // Why this assert can't pass???
        // Consider the case: 000011000, apparently first four zeros are
        // not counted, that also explains why we need two `cnts` here.
        // At the same time also explains why we need a `zero` flag here..
        // assert(cnt_zero + cnt_one == sz(bits));
        return cnt_zero >= cnt_one;
    }
    if (!small && dp[p][cnt_zero][cnt_one] != -1) {
        return dp[p][cnt_zero][cnt_one];
    }
    ll ret = 0;
    int end = small ? bits[p] : 1;
    for (int i = 0; i <= end; ++i) {
        bool new_zero = zero && i == 0;
        int new_cnt_zero = new_zero ? 0 : cnt_zero + (i == 0);
        int new_cnt_one = new_zero ? 0 : cnt_one + (i == 1);
        ret += dfs(p - 1, new_cnt_zero, new_cnt_one, new_zero, small && (i == end));
    }
    if (!small) {
        dp[p][cnt_zero][cnt_one] = ret;
    }
    return ret;
}

ll solve(ll a) {
    bits.clear();
    while (a) {
        bits.pb(a % 2);
        a /= 2;
    }
    // trace(bits);
    return dfs(sz(bits) - 1, 0, 0, 1, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mst(dp, -1);
    ll a, b;
    cin >> a >> b;
    // trace(a, b, solve(b), solve(a - 1));
    output(solve(b) - solve(a - 1));
    return 0;
}

