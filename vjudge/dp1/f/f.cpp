//============================================================================
// Name        : f
// Date        : Tue Mar 19 12:45:26 CST 2019
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

const ll inf = (ll)1e18 + 7;
void amin(ll &a, ll b) {
    a = min(a, b);
}

void solve() {
    int e, f;
    cin >> e >> f;
    int n; cin >> n;
    vpii a(n);
    for (auto &x : a) {
        cin >> x.x >> x.y;
    }

    f -= e;

    vl dp(f + 1, inf);
    dp[0] = 0;
    for (int weight = 0; weight <= f; ++weight) {
        for (int i = 0; i < n; ++i) {
            if (weight + a[i].y <= f) {
                amin(dp[weight + a[i].y], dp[weight] + a[i].x);
            }
        }
    }

    ll ret = dp[f];
    if (ret != inf) {
        cout << "The minimum amount of money in the piggy-bank is "
             << ret << ".\n";
    } else {
        cout << "This is impossible.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

