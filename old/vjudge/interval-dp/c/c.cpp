//============================================================================
// Name        : c
// Date        : Fri Apr  5 22:45:45 CST 2019
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
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

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

const int mod = (int)1e9 + 7;
const int maxn = (int)1000;
string a;
int dp[maxn][maxn][3][3];

inline bool check(int c1, int c2) {
    if (c1 == 0) {
    // If the left bracket is not colored.
        return 1;
    } else if (c2 == 0) {
    // If the right bracket is not colored.
        return 1;
    } else if (c1 != c2) {
    // If the colors are different.
        return 1;
    } else {
        return 0;
    }
}

int rec(int lo, int hi, int cl, int cr) {
    int& ret = dp[lo][hi][cl][cr];
    if (ret != -1) {
        return ret;
    }
    if (lo >= hi) {
        return ret = check(cl, cr);
    }
    int k = 0, i;
    for (i = lo; i <= hi; ++i) {
        if (a[i] == '(') {
            ++k;
        } else {
            --k;
        }
        if (k == 0) {
            break;
        }
    }
    ret = 0;
    for (int L = 0; L < 3; ++L) {
        for (int R = 0; R < 3; ++R) {
            if (L + R > 0 && L * R == 0) {
            // Each pair of matching brackets only one of them is colored.
                if (check(cl, L)) {
                // No two neighboring colored brackets have the same color.
                    ll tmp = (ll)rec(lo + 1, i - 1, L, R) * rec(i + 1, hi, R, cr);
                    ret = (ret + tmp) % mod;
                }
            }
        }
    }
    return ret;
}

void solve() {
    cin >> a;
    mst(dp, -1);
    output(rec(0, sz(a) - 1, 0, 0));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
