//============================================================================
// Name        : f
// Date        : Tue Mar 12 09:34:58 CST 2019
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
    int n, a, b;
    cin >> n >> a >> b;
    string ss; cin >> ss;
    ss = "$" + ss;

    // s1: [....<--i....]
    // s2: [.......<--j...]
    // Compute Longest common prefix at position [i, j] towards left.
    vvi lcp(n + 1, vi(n + 1));
    fori (i, 1, n + 1) fori (j, 1, n + 1) {
        if (ss[i] == ss[j]) {
            lcp[i][j] = lcp[i - 1][j - 1] + 1;
        }
    }

    // dp[i] = min(dp[i-1] + a,
    //             dp[l-1] + b if [l,i] is a substring of [1,l-1])
    // [....<--j....<--i...]
    vi dp(n + 1);
    fori (i, 1, n + 1) {
        dp[i] = dp[i - 1] + a;
        fori (j, 1, i) {
            int x = min(i - j, lcp[i][j]);
            dp[i] = min(dp[i], dp[i - x] + b);
        }
    }
    output(dp[n]);
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

void test_z() {
// "aaaaa" - [0,4,3,2,1]
// "aaabaab" - [0,2,1,0,2,1,0]
// "abacaba" - [0,0,1,0,3,0,1]
    vi a = z_function("aaaaa");
    vi b = z_function("aaabaab");
    vi c = z_function("abacaba");
    trace(a, b, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // solve();
    test_z();
    return 0;
}

