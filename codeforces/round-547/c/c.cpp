//============================================================================
// Name        : c
// Date        : Wed Mar 20 21:26:14 CST 2019
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
    int n; cin >> n;
    vi a(n - 1);
    for (auto &t : a) {
        cin >> t;
    }

    int mx = 0, mi = (int) 2e5 + 7;
    vi d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (i == 0) {
            d[i] = a[i];
        } else {
            d[i] = d[i - 1] + a[i];
        }
        mx = max(d[i], mx);
        mi = min(d[i], mi);
    }
    // trace(mx, mi, d);
    vi ret;
    for (int a1 = 1; a1 <= n; ++a1) {
        if (0 < a1 + mx && a1 + mx <= n &&
            0 < a1 + mi && a1 + mi <= n) {
            ret.pb(a1);
            for (int i = 0; i < n - 1; ++i) {
                ret.pb(a1 + d[i]);
            }
            break;
        }
    }

    bool ok = 1;
    if (sz(ret) != n) {
        ok = 0;
    } else {
        vi tmp = ret;
        sort(all(tmp));
        for (int i = 0; i < n; ++i) {
            if (tmp[i] != i + 1) {
                ok = 0;
                break;
            }
        }
    }

    if (ok) {
        par(ret, 0, sz(ret), 0);
    } else {
        output(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

