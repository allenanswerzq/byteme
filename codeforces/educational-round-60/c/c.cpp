//============================================================================
// Name        : c
// Date        : Mon Feb 25 10:47:19 CST 2019
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
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << "\n"
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"

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

#define x first
#define y second

const ll inf = (ll) 1e18 + 7;

bool check(ll& days, pii& st, pii& fi, int& n, vpii& wind) {
    ll k = days / n, r = days % n;
    ll xx = st.x + k * (ll)wind[n].x + wind[r].x;
    ll yy = st.y + k * (ll)wind[n].y + wind[r].y;
    ll dd = abs(xx - fi.x) + abs(yy - fi.y);
    return (dd <= days);
}

void solve() {
    pii st, fi;
    cin >> st.x >> st.y >> fi.x >> fi.y;
    int n; string ss;
    cin >> n >> ss;
    // Compute how the wind only will affect the ship.
    vpii wind(n + 1);
    fori (i, 0, n) {
        int dx, dy;
        if (ss[i] == 'U') {
            dx = 0, dy = 1;
        } else if (ss[i] == 'D') {
            dx = 0, dy = -1;
        } else if (ss[i] == 'L') {
            dx = -1, dy = 0;
        } else {
            dx = 1, dy = 0;
        }
        wind[i + 1].x = wind[i].x + dx;
        wind[i + 1].y = wind[i].y + dy;
    }

    ll lo = 0, hi = inf;
    while (hi > lo) {
        ll mid = lo + (hi - lo) / 2;
        trace(lo, hi, mid);
        if (check(mid, st, fi, n, wind)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    output((hi == inf ? -1: hi));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

