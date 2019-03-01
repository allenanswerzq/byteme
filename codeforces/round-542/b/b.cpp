//============================================================================
// Name        : b
// Date        : Fri Mar  1 10:30:54 CST 2019
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

void solve() {
    int n; cin >> n;
    map<int, vi> mp;
    fori (i, 0, 2 * n) {
        int x; cin >> x;
        mp[x].pb(i);
    }

    ll ret = 0;
    ll x, y;
    x = y = 0;
    fora (m, mp) {
        vi p = m.second;
        assert(sz(p) == 2);
        ll a = p[0], b = p[1];
        ll da = abs(a - x) + abs(b - y);
        ll db = abs(a - y) + abs(b - x);
        if (da > db) {
            ret += db;
            x = b, y = a;
        } else {
            ret += da;
            x = a, y = b;
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

