//============================================================================
// name        : a
// date        : sun mar 24 11:59:57 cst 2019
// author      : landcold7
// description : actions speak louder more than words
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
#define jam(x, n) cout << "case #" << x << ": " << n << "\n"
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

const ll inf = (ll)1e18 + 7;

void solve(int cs) {
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (auto& t : a) {
        cin >> t;
    }

    sort(a.rbegin(), a.rend());
    // trace(a);
    ll ret = inf, win = 0, mx = a[0];
    for (int i = 0; i < n; ++i) {
        if (i < p) {
            win += a[i];
        } else {
            win -= a[i - p];
            mx = a[i - p + 1];
            win += a[i];
        }
        if (i >= p - 1) {
            // trace(i, win, mx, p);
            ret = min(ret, mx * p - win);
        }
    }

    jam(cs, ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}

