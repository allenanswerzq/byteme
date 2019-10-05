//============================================================================
// Name        : d
// Date        : Wed Apr  3 17:25:22 CST 2019
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
    double p; int n;
    cin >> p >> n;
    vector<pair<int, double>> a(n);
    int sum_money = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        sum_money += a[i].x;
    }
    // dp[i] denotes probability of getting caught if we got `i` money.
    vector<double> dp(sum_money + 1, 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int money = sum_money; money >= 1; --money) {
            int extra = money - a[i].x;
            if (extra >= 0) {
                dp[money] = min(dp[money], dp[extra] + (1 - dp[extra]) * a[i].y);
            }
        }
    }
    // trace(dp);
    int ret = 0;
    for (int i = 0; i <= sum_money; ++i) {
        if (dp[i] < p) {
            ret = i;
        }
    }
    jam(cs, ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}

