//============================================================================
// Name        : h
// Date        : Tue Mar 19 15:52:19 CST 2019
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

void amin(int &a, int b) {
    a = min(a, b);
}

const int inf = (int)1e9 + 7;

void solve() {
    int n; cin >> n;
    vi a(n + 1), b(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    // trace(a, b);

    vi dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        amin(dp[i], dp[i - 1] + a[i]);
        if (i >= 2) {
            amin(dp[i], dp[i - 2] + b[i - 1]);
        }
    }

    int hh, mm, ss;
    ss = dp[n];
    hh = ss / 3600 + 8, ss = ss % 3600;
    mm = ss / 60, ss = ss % 60;
    string am = (hh >= 12 ? "pm" : "am");
    hh %= 12;
    if (hh == 0) hh = 12;
    printf("%02d:%02d:%02d %s\n", hh, mm, ss, am.c_str());

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

