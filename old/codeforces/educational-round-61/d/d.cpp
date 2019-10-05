//============================================================================
// Name        : d
// Date        : Tue Mar 12 19:38:08 CST 2019
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

// ref: https://fihopzz.blogspot.com/2013/07/enter-post-title-here-binary-search-and.html

ll inf = (ll)2e12 + 1234;
int n, k;
vl aa, bb;

ll cost(ll x, ll y) {
    return x / y + 1;
}

bool check(ll mid) {
    priority_queue<pair<ll, ll>> fail;
    vl cc = aa;
    fori (i, 0, n) {
        fail.emplace(-cost(cc[i], bb[i]), i);
    }

    bool ok = 1;
    fori (i, 1, k + 1) {
        auto it = fail.top(); fail.pop();
        it.first = -it.first;
        if (it.first < i) {
        // If at this time, the one that power down fastest already dead.
            ok = 0;
            break;
        }

        if (it.first > k) {
        // Even the down fastest one can live without power off.
            break;
        }

        // Otherwise, change the down fastest laptop for one minute.
        int v = it.second;
        cc[v] += mid;
        fail.emplace(-cost(cc[v], bb[v]), v);
    }
    return ok;
}

void solve() {
    cin >> n >> k;
    aa = vl(n), bb = vl(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    fori (i, 0, n) {
        cin >> bb[i];
    }

    // invariant relation: f[lo] < target <= f[hi]
    // [f[0], f[1], f[2], ... f[x], f[x+1], ...f[n]]
    ll lo = -1, hi = inf;
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        // trace(lo, hi, mid);
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    output(hi == inf ? -1 : hi);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

