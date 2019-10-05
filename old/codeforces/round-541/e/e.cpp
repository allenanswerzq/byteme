//============================================================================
// Name        : e
// Date        : Thu Feb 28 12:08:00 CST 2019
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
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"

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

string mul(string& s, string& t) {
    string ret;
    fora (c, s) {
        ret += (t + string(1, c));
    }
    ret += t;
    return ret;
}

void solve() {
    int n; cin >> n;
    vs aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    string ss = mul(aa[0], aa[1]);
    fori (i, 2, n) {
        ss += mul(ss, aa[i]);
    }

    trace(ss);

    int ret = 0;
    fori (i, 0, sz(ss)) {
        int c = 1;
        while (i + 1 < sz(ss) && ss[i] == ss[i + 1]) {
            ++c, ++i;
        }
        ret = max(ret, c);
    }

    output(ret);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

