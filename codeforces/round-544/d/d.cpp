//============================================================================
// Name        : d
// Date        : Fri Mar 15 14:16:00 CST 2019
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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    fori (i, 0, n) {
        cin >> a[i];
    }
    fori (i, 0, n) {
        cin >> b[i];
    }

    map<pii, int> frac;
    fori (i, 0, n) {
        if (a[i]) {
            int c = gcd(a[i], b[i]);
            frac[{b[i] / c, a[i] / c}]++;
        } else if (!b[i]) {
            frac[{0, 0}]++;
        }
    }

    int ret = 0;
    for (auto& it : frac) {
        if (it.x != pii(0, 0)) {
            ret = max(ret, it.y);
        }
    }
    output(ret + frac[pii(0, 0)]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

