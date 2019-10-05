//============================================================================
// Name        : f
// Date        : Wed Mar 13 09:30:45 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define first x
#define second y
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

const int maxn = 500 + 7;
int dp[maxn][maxn];
string ss;
int rec(int l, int r) {
    int &ret = dp[l][r];
    if (ret != -1) return ret;

    if (l > r) return ret = 0;
    if (l == r) return ret = 1;

    ret = 1 + rec(l + 1, r);
    // [...l...i....r...]
    for (int i = l; i <= r; ++i) {
        if (ss[l] == ss[i]) {
            ret = min(ret, rec(l + 1, i - 1) + rec(i, r));
        }
    }
    return dp[l][r] = ret;
}


int rec2(int l, int r) {
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    if (l > r) return ret = 0;
    if (l == r) return ret = 1;

    // [...l...i...r...]
    ret = 1 + rec2(l, r - 1);
    for (int i = r - 1; i >= l; --i) {
        if (ss[i] == ss[r]) {
            ret = min(ret, rec2(l, i) + rec2(i + 1, r - 1));
        }
    }
    return dp[l][r] = ret;
}

void solve() {
    int n; cin >> n;
    cin >> ss;
    mst(dp, -1);
    output(rec2(0, n - 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

