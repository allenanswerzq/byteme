//============================================================================
// Name        : f
// Date        : Wed Feb 20 10:59:11 CST 2019
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

template <class T>
void amax(T& a, T b) {
    a = max(a, b);
}

const int inf = (int) 1e9 + 7;
void solve() {
    string ss, tt;
    cin >> ss >> tt;

    int a = sz(ss), b = sz(tt);
    using pip = pair<int, pii>;
    vector<vector<pip>> dp(a + 1, vector<pip>(b + 1, {-inf, {0, 0}}));
    dp[0][0] = {0, {0, 0}};
    fori (i, 0, a) {
        fori (j, 0, b) {
            if (ss[i] == tt[j]) {
                amax(dp[i+1][j+1], {dp[i][j].first + 1, {i, j}});
            }
            amax(dp[i+1][j], {dp[i][j].first, {i, j}});
            amax(dp[i][j+1], {dp[i][j].first, {i, j}});
        }
    }

    pip mx = {0, {0, 0}};
    fori (i, 0, a + 1) {
        fori (j, 0, b + 1) {
            amax(mx, {dp[i][j].first, {i, j}});
        }
    }
    trace(dp, mx);
    pii cur = mx.second;
    string ret;
    while (mx.first && !(cur.first == 0 || cur.second == 0)) {
        int i = cur.first, j = cur.second;
        pii pre = dp[i][j].second;
        if (pre == pii(i - 1, j - 1)) {
            assert(ss[i - 1] == tt[j - 1]);
            ret = ss[i - 1] + ret;
        }
        cur = pre;
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

