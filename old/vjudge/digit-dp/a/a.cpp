//============================================================================
// Name        : a
// Date        : Sat Mar 30 10:14:53 CST 2019
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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// TODO
// Total memory: 20 * 2527 * 2527 * 8 / 2**20 ~ 880M
// ll dp[20][2527][2527];
const int mod = 2520;
ll dp[25][2527][48 + 7];
vi bits, ha;
ll dfs(int p, ll pre_sum, ll pre_lcm, bool small) {
    if (p == -1) {
        return pre_sum % pre_lcm == 0;
    }
    int idx = ha[pre_lcm];
    if (!small && dp[p][pre_sum][idx] != -1) {
        return dp[p][pre_sum][idx];
    }
    ll ret = 0;
    int end = small ? bits[p] : 9;
    for (int i = 0; i <= end; ++i) {
        ll cur_sum = (pre_sum * 10 + i) % mod;
        ll cur_lcm = pre_lcm;
        if (i > 0) {
            cur_lcm = lcm(i, pre_lcm);
        }
        ret += dfs(p - 1, cur_sum, cur_lcm, small && i == end);
    }
    // If we haven't see smaller digit yet.
    if (!small) {
        dp[p][pre_sum][idx] = ret;
    }
    return ret;
}

ll solve(ll a) {
    bits.clear();
    while (a) {
        bits.pb(a % 10);
        a = a / 10;
    }
    return dfs(sz(bits) - 1, 0, 1, 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ha = vi(mod + 7);
    int k = 0;
    for (int i = 1; i <= mod; ++i) {
        if (mod % i == 0) {
            ha[i] = k++;
        }
    }

    // Why reset dp array here???
    mst(dp, -1);

    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        ll l, r;
        cin >> l >> r;
        output(solve(r) - solve(l - 1));
    }
    return 0;
}

