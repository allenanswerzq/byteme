//============================================================================
// Name        : d
// Date        : Tue Mar 19 10:12:10 CST 2019
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

struct Work {
    string name;
    int dline;
    int need;
    // friend dbstream& operator<<(dbstream& os, Work& w) {
    //     os << "Work(" << w.name << " " << w.dline << " " << w.need << ")\n";
    //     return os;
    // }
};

const int inf = (int)1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<Work> a(n);
    for (auto &x : a) {
        cin >> x.name >> x.dline >> x.need;
    }

    vi dp(1 << n, inf), pre(1 << n);
    dp[0] = 0;
    for (int stat = 0; stat < (1 << n); ++stat) {
        for (int i = 0; i < n; ++i) {
            if (stat & (1 << i)) continue;
            // If the work `i` has not been done in this state.
            // Compute how many days needed to finish `i`th work.
            int days = 0;
            for (int k = 0; k < n; ++k) {
                if (stat & (1 << k)) {
                    days += a[k].need;
                }
            }
            days += a[i].need;

            int reduce = 0;
            if (days > a[i].dline) {
                reduce = days - a[i].dline;
            }

            if (dp[stat | (1 << i)] > dp[stat] + reduce) {
                dp[stat | (1 << i)] = dp[stat] + reduce;
                pre[stat | (1 << i)] = i;
            }
        }
    }

    trace(dp, pre);

    output(dp[(1 << n) - 1]);
    int stat = (1 << n) - 1;
    vs order;
    while (stat) {
        int p = pre[stat];
        order.pb(a[p].name);
        stat &= ~(1 << p);
    }
    reverse(all(order));
    for (auto x : order) {
        output(x);
    }
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

