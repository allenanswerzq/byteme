//============================================================================
// Name        : c
// Date        : Sun Mar 10 10:42:38 CST 2019
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
    int n, k;
    cin >> n >> k;
    vi aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    priority_queue<pii, vpii, greater<pii>> dq;
    fori (i, 0, k) {
        dq.push({aa[i], i});
    }

    vi tt(n);
    while (sz(dq)) {
        auto cur = dq.top(); dq.pop();
        int t = cur.first, i = cur.second;
        // trace(cur, t, i);
        tt[i] = t;
        if (k < n) {
            dq.push({t + aa[k], k});
            ++k;
        }
    }

    sort(all(tt));
    trace(tt);

    int t = 0, ret = 0, m = 0, d = 0, e = 0;
    fori (i, 0, n) {
        int c = tt[i];
        trace(c, t, d, ret, e, m);
        if (d && c - t >= d) {
            ret += e;
        }
        e = 1;
        // How many tests are finished at this time.
        while (i + 1 < n && tt[i] == tt[i + 1]) {
            ++e, ++i;
        }
        m += e;
        d = (m * 1.0 / n * 100 + 0.5);
        t = c;
        trace(e, m, i, d, t, c, ret);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

