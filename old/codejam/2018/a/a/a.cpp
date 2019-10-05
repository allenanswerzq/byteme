//============================================================================
// Name        : a
// Date        : Sat Mar 23 16:37:32 CST 2019
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

inline int odd(string s) {
    int n = sz(s), odd = -1;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') & 1) {
            odd = i;
            break;
        }
    }
    return odd;
}

ll up(string s) {
    int ix = odd(s);
    // trace(ix, s);
    if (ix == -1) {
        return stoll(s);
    }

    // 86912 -> 88000
    // 6488962 -> 6600000
    // 88892
    // 91112

    for (int i = ix + 1; i < sz(s); ++i) {
        s[i] = '0';
    }

    if (ix == 0) {
        if (s[ix] == '9') {
            s[ix] = '0';
            s.insert(s.begin(), '2');
        } else {
            s[ix]++;
        }
    } else {
        if (s[ix] == '9') {
            s[ix] = '0';
            s[ix - 1] += 1;
        } else {
            s[ix]++;
        }
    }

    // trace(s);
    return up(s);
}

ll down(string s) {
    int ix = odd(s);
    if (ix == -1) {
        return stoll(s);
    }

    s[ix] -= 1;
    for (int i = ix + 1; i < sz(s); ++i) {
        s[i] = '8';
    }
    return stoll(s);
}

void solve(int cs) {
    ll n; cin >> n;
    string s = to_string(n);
    ll x = down(s);
    ll y = up(s);
    // trace(n, x, y, n - x, y - n);
    assert(n >= x);
    assert(y >= n);
    jam(cs, min(n - x, y - n));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}

