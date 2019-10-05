//============================================================================
// Name        : g
// Date        : Tue Mar 19 13:32:45 CST 2019
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
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
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

void amax(int &a, int b) {
    a = max(a, b);
}

const int maxn = (int)1e5 + 7;
int n;
void solve() {
    int tmx = 0;
    vvi dp(maxn, vi(15));
    for (int i = 0; i < n; ++i) {
        int x, t;
        cin >> x >> t;
        dp[t][x + 1]++;
        tmx = max(tmx, t);
    }

    for (int time = tmx - 1; time >= 0; --time) {
        for (int i = 1; i <= 11; ++i) {
            int tmp = dp[time + 1][i];
            amax(tmp, dp[time + 1][i + 1]);
            amax(tmp, dp[time + 1][i - 1]);
            dp[time][i] += tmp;
        }
    }

    output(dp[0][6]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

