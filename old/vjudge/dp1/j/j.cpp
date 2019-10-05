//============================================================================
// Name        : j
// Date        : Tue Mar 19 17:17:47 CST 2019
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

struct Mice {
    int weight;
    int speed;
    int idx;
    // friend dbstream& operator<<(dbstream& os, Mice &m) {
    //     os << "Mice(" << m.weight << " " << m.speed
    //        << " " << m.idx << ")\n";
    //     return os;
    // }
};

void solve() {
    int w, s;
    vector<Mice> a;
    int n = 0;
    while (cin >> w >> s) {
        a.pb({w, s, n++});
    }

    sort(all(a), [](Mice &a, Mice &b) {
        if (a.weight == b.weight) {
            return a.speed < b.speed;
        }
        return a.weight > b.weight;
    });

    vi dp(n, 1), pre(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j].weight > a[i].weight && a[j].speed < a[i].speed) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[a[i].idx] = a[j].idx;
                }
            }
        }
    }

    int ret = 0, idx = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > ret) {
            ret = dp[i];
            idx = a[i].idx;
        }
    }

    // trace(ret, idx, a, dp, pre);

    output(ret);
    vi b;
    while (idx != -1) {
        b.pb(idx + 1);
        idx = pre[idx];
    }
    // reverse(all(b));
    for (auto x : b) {
        output(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

