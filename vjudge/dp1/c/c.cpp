//============================================================================
// Name        : c
// Date        : Mon Mar 18 21:07:27 CST 2019
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

struct Block {
    int l, w, h;
    friend dbstream& operator<<(dbstream& os, Block& b) {
        return os << "Block(" << b.l << " " << b.w << " " << b.h << ")\n";
    }
};

void amax(int &a, int b) {
    a = max(a, b);
}

int n, cs;
void solve() {
    vector<Block> base;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        base.pb({x, y, z});
        base.pb({y, x, z});
        base.pb({x, z, y});
        base.pb({z, x, y});
        base.pb({y, z, x});
        base.pb({z, y, x});
    }
    sort(all(base), [](Block& a, Block &b){
        if (a.l == b.l) return a.w > b.w;
        return a.l > b.l;
    });
    // trace(base);
    // Try use each one of these blocks as a top block.
    vi dp(sz(base));
    for (int i = 0; i < sz(base); ++i) {
        dp[i] = base[i].h;
        for (int j = 0; j < i; ++j) {
            if (base[j].l > base[i].l && base[j].w > base[i].w) {
                amax(dp[i], dp[j] + base[i].h);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < sz(base); ++i) {
        amax(ret, dp[i]);
    }
    cout << "Case " << cs << ": maximum height = " << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cs = 0;
    while (cin >> n && n) {
        ++cs;
        solve();
    }
    return 0;
}

