//============================================================================
// Name        : e
// Date        : Thu Mar 21 17:24:07 CST 2019
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

void solve() {
    ll h; int n;
    cin >> h >> n;

    vi a(n);
    ll t = h, mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum -= a[i];
        t += a[i];
        if (t <= 0) {
            output(i + 1);
            return;
        }
        mx = max(mx, sum);
    }

    if (sum <= 0) {
        output(-1);
        return;
    }

    ll cycle = (h - mx) / sum;
    // trace(h, sum, mx, cycle, h, cycle);
    h -= cycle * sum;
    cycle = cycle * n;
    for (int i = 0; ; ++i) {
        h += a[i % n];
        ++cycle;
        if (h <= 0) {
            output(cycle);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

