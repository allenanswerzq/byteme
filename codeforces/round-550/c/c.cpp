//============================================================================
// Name        : c
// Date        : Mon Apr  1 21:53:57 CST 2019
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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto& t : a) {
        cin >> t;
    }
    sort(all(a));
    vi b, c;
    for (int i = 0; i < n; ++i) {
        if (sz(b) == 0 || a[i] > b.back()) {
            b.pb(a[i]);
        } else {
            c.pb(a[i]);
        }
    }
    trace(b, c);
    for (int i = 0; i < sz(c); ++i) {
        if (i + 1 < sz(c) && c[i] >= c[i + 1]) {
            output("NO");
            return;
        }
    }
    output("YES");
    cout << sz(b) << "\n";
    par(b, 0, sz(b), 0);
    cout << sz(c) << "\n";
    reverse(all(c));
    par(c, 0, sz(c), 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

