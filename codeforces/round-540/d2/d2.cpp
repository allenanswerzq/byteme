//============================================================================
// Name        : d2
// Date        : Tue Feb 26 14:56:09 CST 2019
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
    int n, m;
    cin >> n >> m;
    vi aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    sort(aa.rbegin(), aa.rend());

    int lo = 1, hi = n + 1;
    while (hi > lo) {
        // trace(hi, lo);
        int mid = lo + (hi - lo) / 2;

        ll r = 0;
        fori (i, 0, n) {
            r += max(0, aa[i] - i / mid);
        }

        if (r >= m) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    if (hi == n + 1) {
        output(-1);
    } else {
        output(hi);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

