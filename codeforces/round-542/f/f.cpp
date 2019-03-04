//============================================================================
// Name        : f
// Date        : Sun Mar  3 10:45:21 CST 2019
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

// TODO: ugly code...
void solve() {
    int k; cin >> k;
    vi aa; aa.pb(-1);
    int x = k + 2, mx = 1000000;
    int n = x / mx, r = x % mx;
    int m = n > 1 ? mx : x;

    trace(k, x, n, r, m);

    fori (i, 0, n) {
        aa.pb(m);
    }

    if (r) {
        r = r + n;
        trace(r);
        if (r <= mx) {
            aa.pb(r);
        } else {
            aa.pb(mx);
            aa.pb(r % mx + 1);
        }
    }

    if (!r && n > 1) {
        if (n <= mx) {
            aa.pb(n);
        } else {
            aa.pb(mx);
            aa.pb(n % mx);
        }
    }

    if (sz(aa) > 2000) {
        output(-1);
    } else {
        ll sum = accumulate(all(aa), 0);
        assert (sum - sz(aa) + 1 == k);
        output(sz(aa));
        par(aa, 0, sz(aa), 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

