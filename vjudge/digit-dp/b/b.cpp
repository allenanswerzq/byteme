//============================================================================
// Name        : b
// Date        : Mon Apr  1 09:02:30 CST 2019
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

ll l, r; int k;
vi bits;
ll dp[25][1 << 10][12];

int count(int& state) {
    int ret = 0;
    for (int i = 0; i < 10; ++i) {
        if (state & (1 << i)) {
            ++ret;
        }
    }
    return ret;
}

inline int nxt_state(int& state, int digit) {
// Finds the next state if we adding a `digit` into this sequence.
    for (int i = digit; i < 10; ++i) {
        if (state & (1 << i)) {
        // If there already exist a digit that is greater than we just added.
        // in old state, clean that digit out...
            return ((state ^ (1 << i)) | (1 << digit));
        }
    }
    return (state | (1 << digit));
}


ll dfs(int p, int state, bool zero, bool small) {
    // trace(bits, p, state, zero, small);
    if (p == -1) {return count(state) == k;
    }

    if (!small && dp[p][state][k] != -1) {
        return dp[p][state][k];
    }

    ll ret = 0;
    int end = small ? bits[p] : 9;
    for (int i = 0; i <= end; ++i) {
        bool new_zero = zero && (i == 0);
        int new_state = new_zero ? 0 : nxt_state(state, i);
        // trace(p - 1, i, state, new_state, new_zero, small);
        ret += dfs(p - 1, new_state, new_zero, small && (i == end));
    }

    if (!small) {
        dp[p][state][k] = ret;
    }

    return ret;
}

ll solve(ll a) {
    bits.clear();
    // mst(dp, -1);
    while (a) {
        bits.pb(a % 10);
        a /= 10;
    }
    // par(dp[2], 0, 100, 1);
    return dfs(sz(bits) - 1, 0, 1, 1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Again, why reset dp array here??
    // Shouldn't it be reseted in `solve`?? but in that way it will make
    // this program runs pretty slow..

    // For this program, dp values can be shared even between different
    // input cases, so magic here...
    mst(dp, -1);

    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        cin >> l >> r >> k;
        // trace(l, r, k);
        ll ret = solve(r) - solve(l - 1);
        jam(i, ret);
    }
    return 0;
}

