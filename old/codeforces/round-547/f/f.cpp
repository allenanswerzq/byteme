//============================================================================
// Name        : f
// Date        : Thu Mar 21 19:28:36 CST 2019
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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<ll, vpii> mp;
    for (int R = 0; R < n; ++R) {
        ll sum = 0;
        for (int L = R; L >= 0; --L) {
            sum += a[L];
            mp[sum].pb({L, R});
        }
    }

    trace(mp);
    int ret = 0;
    vpii g;
    for (auto it : mp) {
        vpii p = it.y;
        int last = -1, cur = 0;
        vpii t;
        for (auto s : p) {
            if (s.x > last) {
                ++cur;
                t.pb(s);
                last = s.y;
            }
        }
        if (ret < cur) {
            ret = cur;
            g = t;
        }
    }
    output(ret);
    for (auto it : g) {
        cout << it.x + 1 << " " << it.y + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

