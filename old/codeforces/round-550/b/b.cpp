//============================================================================
// Name        : b
// Date        : Mon Apr  1 21:39:25 CST 2019
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
    vi a(n), o, e;
    for (auto &t : a) {
        cin >> t;
        if (t % 2) {
            o.pb(t);
        } else {
            e.pb(t);
        }
    }
    sort(all(o));
    sort(all(e));
    int p = sz(o), m = sz(e);
    if (p == m && abs(p - m) == 1) {
        output(0);
        return;
    }
    ll ret = 0;
    for (int i = 0; i < abs(p - m) - 1; ++i) {
        if (p > m) {
            ret += o[i];
        } else {
            ret += e[i];
        }
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

