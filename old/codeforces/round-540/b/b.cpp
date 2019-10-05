//============================================================================
// Name        : b
// Date        : Mon Feb 25 22:11:27 CST 2019
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

void solve() {
    int n; cin >> n;
    vi aa(n);
    ll bo, be;
    bo = be = 0;
    fori (i, 0, n) {
        cin >> aa[i];
        if (i & 1) {
            be += aa[i];
        } else {
            bo += aa[i];
        }
    }

    ll fo, fe, ret;
    fo = fe = ret = 0;
    fori (i, 0, n) {
        if (i & 1) {
            be -= aa[i];
        } else {
            bo -= aa[i];
        }

        if (fo + be == fe + bo) {
            ++ret;
        }

        if (i & 1) {
            fe += aa[i];
        } else {
            fo += aa[i];
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

