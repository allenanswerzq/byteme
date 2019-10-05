//============================================================================
// Name        : c
// Date        : Tue Feb 19 22:22:47 CST 2019
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

void amax(int& a, int b) {
    a = max(a, b);
}

void solve() {
    int n; cin >> n;
    vi dp(3, 0);
    fori (day, 0, n) {
        vi new_dp(3, 0), aa(3);
        fori (i, 0, 3)  {
            cin >> aa[i];
        }

        fori (i, 0, 3) fori (j, 0, 3) {
            if (i != j) {
                new_dp[j] = max(new_dp[j], dp[i] + aa[j]);
            }
        }
        trace(dp, new_dp);
        dp = new_dp;
    }
    output(max(max(dp[0], dp[1]), dp[2]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

