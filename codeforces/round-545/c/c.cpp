//============================================================================
// Name        : c
// Date        : Mon Mar 18 13:53:56 CST 2019
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

int n, m;
vvi a, ret;

void solve() {
    cin >> n >> m;
    a = vvi(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // n*nlogn
    vvi sort_rows = vvi(n);
    for (int i = 0; i < n; ++i) {
        vi b = a[i];
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        sort_rows[i] = b;
    }

    // m*mlogm
    vvi sort_cols = vvi(m);
    for (int i = 0; i < m; ++i) {
        vi d;
        for (int k = 0; k < n; ++k) {
            d.pb(a[k][i]);
        }
        sort(all(d));
        d.erase(unique(all(d)), d.end());
        sort_cols[i] = d;
    }

    // n * m * logn
    ret = vvi(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vi b = sort_rows[i], d = sort_cols[j];
            int x = lower_bound(all(b), a[i][j]) - b.begin();
            int y = lower_bound(all(d), a[i][j]) - d.begin();
            ret[i][j] = max(x, y) + 1 + max(sz(b) - x - 1, sz(d) - y - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        par(ret[i], 0, m, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

