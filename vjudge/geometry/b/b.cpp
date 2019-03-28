//============================================================================
// Name        : b
// Date        : Thu Mar 28 10:12:18 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
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

int n;
void solve() {
    int m, x1, y1, x2, y2;
    cin >> m >> x1 >> y1 >> x2 >> y2;
    vpii a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    a[n] = {x2, x2};

    sort(all(a));

    vi ret(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int lo = -1, hi = n;
        while (hi - lo > 1) {
            // lo < e && e <= hi
            int mid = lo + (hi - lo) / 2;
            // If x, y is at the left side of the `mid` line
            // (a[mid].x - a[mid.y]) / (y1 - y2) > x - a[mid.y] / (y - y2)
            bool ok = (a[mid].x - a[mid].y) * (y - y2) > (x - a[mid].y) * (y1 - y2);
            // trace(i, lo, hi, mid, ok);
            if (ok) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        // Until here, this `lo < e && e <= hi` relation still holds,
        // trace(i, x, y, lo);
        ret[lo + 1]++;
    }

    vi cnt(1200);
    for (int i = 0; i <= n; ++i) {
        cnt[ret[i]]++;
    }

    output("Box");
    for (int t = 1; t < 1200; ++t) {
        if (cnt[t] > 0) {
            cout << t << ": " << cnt[t] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

