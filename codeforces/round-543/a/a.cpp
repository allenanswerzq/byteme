//============================================================================
// Name        : a
// Date        : Sat Mar  9 21:14:43 CST 2019
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), b(n + 1);
    fori (i, 1, n + 1) {
        cin >> a[i];
    }

    fori (i, 1, n + 1) {
        cin >> b[i];
    }

    int ret = 0;
    fori (i, 1, k + 1) {
        int x; cin >> x;
        fori (j, 1, n + 1) {
            // Same school but meet a stronger one.
            if (b[j] == b[x] && a[j] > a[x]) {
                ++ret;
                break;
            }
        }
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

