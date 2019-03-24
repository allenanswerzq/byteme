//============================================================================
// Name        : b
// Date        : Sat Mar 23 18:37:52 CST 2019
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

void solve(int cs) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &t : a) {
        cin >> t;
    }

    vector<double> dp(k + 1);
    dp[0] = accumulate(all(a), 0.0) * 1.0 / n;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i] += max(dp[i - 1], (double)a[j]) * 1.0 / n;
        }
    }
    jam(cs, dp[k]);
}

int binary_search(vector<double> &a, double e) {
    // a[ix] <= e && e < a[ix + 1]
    int lo = -1, hi = sz(a);
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= e) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

void solve_fast(int cs) {
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));
    vector<double> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }

    // k * logn + nlogn(sorting)
    vector<double> dp(k + 1);
    dp[0] = pre[n] * 1.0 / n;
    for (int i = 1; i <= k; ++i) {
        int ix = binary_search(a, dp[i - 1]);
        dp[i] += (ix + 1) * dp[i - 1] * 1.0 / n;
        dp[i] += (pre[n] - pre[ix + 1]) * 1.0 / n;
    }
    jam(cs, dp[k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(6) << fixed;

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve_fast(i);
    }
    return 0;
}

