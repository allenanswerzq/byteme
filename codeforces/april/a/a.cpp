//============================================================================
// Name        : a
// Date        : Mon Apr  1 23:04:19 CST 2019
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

vi aa;
int rec(int lo, int hi) {
    if (hi - lo == 1) {
        return aa[lo] <= aa[hi] ? 2 : 1;
    }
    int n = hi - lo + 1;
    int mid = lo + (hi - lo) / 2;
    int l = rec(lo, mid);
    int r = rec(mid + 1, hi);
    int ret = 0;
    if (l == n / 2 && l == r && aa[mid] <= aa[mid + 1]) {
        ret = n;
    } else {
        ret = max(l, r);
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    aa = vi(n);
    for (auto& t : aa) {
        cin >> t;
    }
    if (n == 1) {
        output(1);
    } else {
        output(rec(0, n - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

