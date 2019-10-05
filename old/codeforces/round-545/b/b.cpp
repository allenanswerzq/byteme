//============================================================================
// Name        : b
// Date        : Mon Mar 18 10:49:13 CST 2019
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

void print(vi& a, int l) {
    for (int i = 0; i < l; ++i) {
        cout << a[i] + 1 << " ";
    }
}

void solve() {
    int n; string ss, tt;
    cin >> n >> ss >> tt;
    vi aa, bb, cc, dd;
    for (int i = 0; i < n; ++i) {
        if (ss[i] == '0') {
            if (tt[i] == '0') {
                // 0 0
                aa.pb(i);
            } else {
                // 0 1
                bb.pb(i);
            }
        } else {
            if (tt[i] == '0') {
                // 1 0
                cc.pb(i);
            } else {
                // 1 1
                dd.pb(i);
            }
        }
    }

    // trace(aa, bb, cc, dd);

    // a + b + c + d = n / 2
    // c + b + 2 * d = nb + nd
    int nb = sz(bb), nd = sz(dd);
    int a, b, c, d;
    for (b = 0; b <= sz(bb); ++b) {
        for (c = 0; c <= sz(cc); ++c) {
            d = nb + nd - (b + c);
            if (0 <= d && d <= 2 * nd && d % 2 == 0) {
                d /= 2;
                a = n / 2 - (b + c) - d;
                if (0 <= a && a <= sz(aa)) {
                    assert(a + b + c + d == n / 2);
                    assert(b + c + 2 * d == nb + nd);
                    print(aa, a);
                    print(bb, b);
                    print(cc, c);
                    print(dd, d);
                    cout << "\n";
                    return;
                }
            }
        }
    }
    output(-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

