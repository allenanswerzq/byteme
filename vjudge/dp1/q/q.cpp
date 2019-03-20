//============================================================================
// Name        : q
// Date        : Wed Mar 20 08:59:32 CST 2019
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

int n, k;
vvi dp, a;
int dfs(int i, int j) {
    if (dp[i][j]) return dp[i][j];
    vpii dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ret = 0;
    for (auto dir : dirs) {
        for (int step = 1; step <= k; ++step) {
            int x = i + dir.x * step;
            int y = j + dir.y * step;
            if (0 <= x && x < n && 0 <= y && y < n
                && a[i][j] < a[x][y]) {
                amax(ret, dfs(x, y));
            }
        }
    }
    ret += a[i][j];
    return dp[i][j] = ret;
}

void solve() {
    a = vvi(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // dp[i][j] denotes the maximum value if we start at the (i, j) position.
    dp = vvi(n, vi(n));
    output(dfs(0, 0));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> k && n != -1 && k != -1) {
        solve();
    }
    return 0;
}

