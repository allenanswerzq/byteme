//============================================================================
// Name        : e
// Date        : Tue Mar 19 12:25:11 CST 2019
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

void amax(ll &a, ll b) {
    a = max(a, b);
}

int n;
void solve() {
    vi a(n);
    for (auto &x : a) {
        cin >> x;
    }

    ll ret = 0;
    vl dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i];
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                amax(dp[i], dp[j] + a[i]);
            }
        }
        amax(ret, dp[i]);
    }
    // trace(dp);
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

