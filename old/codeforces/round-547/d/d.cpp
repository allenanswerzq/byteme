//============================================================================
// Name        : d
// Date        : Wed Mar 20 22:01:35 CST 2019
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
    int n; string a, b;
    cin >> n >> a >> b;
    int A = 26;
    vvi va(A), vb(A);
    vi sa, sb;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '?') {
            sa.pb(i);
        } else {
            va[a[i] - 'a'].pb(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] == '?') {
            sb.pb(i);
        } else {
            vb[b[i] - 'a'].pb(i);
        }
    }

    vpii ret;
    vi ca(A), cb(A);
    for (int i = 0; i < A; ++i) {
        int x = sz(va[i]), y = sz(vb[i]);
        for (int j = 0; j < min(x, y); ++j) {
            ret.pb({va[i][j], vb[i][j]});
        }
        ca[i] = cb[i] = min(x, y);
    }

    for (int i = 0; i < A; ++i) {
        while (ca[i] < sz(va[i]) && sz(sb)) {
            ret.pb({va[i][ca[i]], sb[sz(sb) - 1]});
            ca[i]++;
            sb.pop_back();
        }
    }

    for (int i = 0; i < A; ++i) {
        while (cb[i] < sz(vb[i]) && sz(sa)) {
            ret.pb({sa[sz(sa) - 1], vb[i][cb[i]]});
            cb[i]++;
            sa.pop_back();
        }
    }

    for (int i = 0; i < min(sz(sa), sz(sb)); ++i) {
        ret.pb({sa[i], sb[i]});
    }

    output(sz(ret));
    for (auto it : ret) {
        cout << it.x + 1 << " " << it.y + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

