//============================================================================
// Name        : n
// Date        : Mon Mar  4 15:57:57 CST 2019
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

const ll inf = (ll) 1e18 + 7;

void solve() {
    int n; cin >> n;
    vi aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    auto sum = [&](int lo, int hi) {
        ll s = 0;
        fori (i, lo, hi + 1) {
            s += aa[i];
        }
        return s;
    };

    vector<vl> dp(n, vl(n, inf));
    fori (hi, 0, n) ford (lo, hi, -1) {
        if (lo == hi) {
            dp[lo][hi] = 0;
        } else {
            ll s = sum(lo, hi);
            fori (i, lo, hi) {
                dp[lo][hi] = min(dp[lo][hi], dp[lo][i] + dp[i + 1][hi] + s);
            }
        }
    }

    output(dp[0][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

