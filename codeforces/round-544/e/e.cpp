//============================================================================
// Name        : e
// Date        : Fri Mar 15 14:38:56 CST 2019
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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    fori (i, 0, n) {
        cin >> a[i];
    }
    sort(all(a));

    vi b(n);
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && a[r] - a[l] <= 5) {
            ++r;
        }
        b[l] = r - l;
    }

    // trace(b);
    vvi dp(n + 1, vi(k + 1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            amax(dp[i + 1][j], dp[i][j]);
            if (j + 1 <= k) {
                amax(dp[i + b[i]][j + 1], dp[i][j] + b[i]);
            }
        }
    }
    output(dp[n][k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

