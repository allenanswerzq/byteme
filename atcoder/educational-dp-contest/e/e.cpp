//============================================================================
// Name        : e
// Date        : Wed Feb 20 10:22:05 CST 2019
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

const int inf = (int) 1e9 + 7;

void amin(int &a, int b) {
    a = min(a, b);
}

void solve() {
    int n, w; cin >> n >> w;
    vi ww(n, 0), vv(n, 0);
    fori (i, 0, n) {
        cin >> ww[i] >> vv[i];
    }

    int sum = accumulate(all(vv), 0);

    // dp[i] the mimimum weights with the sum of item's value is `i`
    vi dp(sum + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = sum - vv[i]; j >= 0; --j) {
            amin(dp[j + vv[i]], dp[j] + ww[i]);
        }
    }

    int ret = 0;
    fori (i, 0, sum + 1) {
        if (dp[i] <= w) {
            ret = max(ret, i);
        }
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

