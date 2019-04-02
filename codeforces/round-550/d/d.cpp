//============================================================================
// Name        : d
// Date        : Mon Apr  1 22:40:35 CST 2019
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
const int maxn = (int)2e5 + 7;

struct Op {
   int t, u, v;
};

void solve() {
    int n; cin >> n;
    vi a(n);
    vector<set<int>> h(maxn);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        h[a[i]].insert(i);
    }
    sort(all(a));
    trace(a);
    vpii e;
    for (int i = n - 2; i >= 0; --i) {
        int d = a[i + 1] - a[i];
        while (d) {
            d = a[i + 1] - a[i] - d;
            e.pb({a[i], a[i + 1]});
        }
    }
    trace(e);
    vector<Op> ret;
    for (auto it : e) {
        int x = it.x, y = it.y;
        // Leave it now...
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

