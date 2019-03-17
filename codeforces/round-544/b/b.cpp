//============================================================================
// Name        : b
// Date        : Wed Mar 13 21:57:22 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define first x
#define second y
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
    int n, k;
    cin >> n >> k;
    multiset<int> st;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int r = x % k;
        int p = r ? k - r : 0;
        auto it = st.find(p);
        if (it != st.end()) {
            ++ret;
            st.erase(it);
        } else {
            st.insert(r);
        }
    }
    output(ret * 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

