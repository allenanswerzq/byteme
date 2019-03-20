//============================================================================
// Name        : s
// Date        : Wed Mar 20 11:59:55 CST 2019
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

struct Node {
    int s, e, w;
    bool operator<(const Node &a) const {
        if (a.s == b.s) {
            return a.e < b.e;
        } else {
            return a.s < b.s;
        }
    }
    // friend dbstream& operator<<(dbstream& os, Node &n) {
    //     os << "Node(" << n.s << " " << n.e << " " << n.w << ")\n";
    //     return os;
    // }
};

void amax(int &a, int b) {
    a = max(a, b);
}

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<Node> a(m);
    for (auto &t : a) {
        cin >> t.s >> t.e >> t.w;
    }
    // sort(all(a), [](Node &a, Node &b) {
    //     if (a.s == b.s) {
    //         return a.e < b.e;
    //     } else {
    //         return a.s < b.s;
    //     }
    // });
    sort(all(a));

    vi dp(m);
    for (int i = 0; i < m; ++i) {
        dp[i] = a[i].w;
        for (int j = i - 1; j >=0; --j) {
            if (a[i].e <= n && a[j].e + r <= a[i].s) {
                amax(dp[i], dp[j] + a[i].w);
            }
        }
    }
    // trace(n, m, r, a, dp);
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        amax(ret, dp[i]);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

