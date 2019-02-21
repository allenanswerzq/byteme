//============================================================================
// Name        : h
// Date        : Wed Feb 20 14:23:41 CST 2019
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

const int mod = (int) 1e9 + 7;
void add(int& a, int b) {
    a = a + b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vs gg(n);
    fori (i, 0, n) {
        cin >> gg[i];
    }

    vvi dp(n, vi(m, 0));
    dp[0][0] = 1;
    fori (row, 0, n) {
        fori (col, 0, m) {
            for (auto r : {row, row + 1}) {
                int c = col;
                if (r == row) {
                    c = col + 1;
                }
                if (r < n && c < m && gg[r][c] == '.') {
                    add(dp[r][c], dp[row][col]);
                }
            }
        }
    }
    output(dp[n-1][m-1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

