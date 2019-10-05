//============================================================================
// Name        : b
// Date        : Wed Apr  3 09:57:03 CST 2019
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
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case " << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve(int cs) {
    int n; cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<double> prob(n + 1);
    prob[1] = 1;
    for (int i = 1; i <= n; ++i) {
        int end = min(n, i + 6);
        for (int j = i + 1; j <= end; ++j) {
            prob[j] += prob[i] * 1.0 / (end - i);
        }
    }
    double ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += prob[i] * a[i];
    }
    jam(cs, ret);
}

void solve2(int cs) {
    int n; cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
       cin >> a[i];
    }
    vector<double> dp(n + 1);
    dp[n] = a[n];
    for (int i = n; i >= 1; --i ) {
        int end = min(n, i + 6);
        for (int j = i + 1; j <= end; ++j) {
            dp[i] += (dp[j] + a[i]) * 1.0 / (end - i);
        }
    }
    jam(cs, dp[1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(6) << fixed;

    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        solve2(i);
    }
    return 0;
}

