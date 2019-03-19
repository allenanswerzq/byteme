//============================================================================
// Name        : i
// Date        : Tue Mar 19 16:41:54 CST 2019
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

int n;
void solve() {
    vi a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vi b;
    for (int i = 0; i < n; ++i) {
        bool ok = 0;
        for (int j = 0; j < sz(b); ++j) {
            if (b[j] >= a[i]) {
                ok = 1;
                b[j] = a[i];
                break;
            }
        }
        if (!ok) {
            b.pb(a[i]);
        }
    }
    output(sz(b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        solve();
    }
    return 0;
}

