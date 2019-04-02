//============================================================================
// Name        : g
// Date        : Tue Apr  2 15:06:23 CST 2019
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

const int inf = (int)2e5 + 7;
void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &t : a) {
        cin >> t;
    }
    vpii inc, dec;
    inc.pb({-1, -1}), dec.pb({inf, -1});
    for (int i = 0; i < n; ++i) {
        bool b = a[i] > inc.back().x;
        bool c = a[i] < dec.back().x;
        if (b && !c) {
            inc.pb({a[i], i});
        } else if (!b && c) {
            dec.pb({a[i], i});
        } else if (b && c) {
            if (i + 1 < n && a[i + 1] > a[i]) {
                inc.pb({a[i], i});
            } else {
                dec.pb({a[i], i});
            }
        } else {
            output("NO");
            return;
        }
    }
    // trace(inc, dec);
    output("YES");
    vi ret(n, 0);
    for (auto it : dec) {
        // trace(it);
        if (it.y != -1) {
            ret[it.y] = 1;
        }
    }
    par(ret, 0, sz(ret), 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

