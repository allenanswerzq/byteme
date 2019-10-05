//============================================================================
// Name        : d
// Date        : Mon Mar 18 16:46:18 CST 2019
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

vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int ones = 0, zeros = 0;
    int A = sz(a), B = sz(b);
    for (int i = 0; i < A; ++i) {
        if (a[i] == '0') {
            ++zeros;
        } else {
            ++ones;
        }
    }
    for (int i = 0; i < B; ++i) {
        if (b[i] == '0') {
            --zeros;
        } else {
            --ones;
        }
    }

    if (zeros < 0 || ones < 0) {
        output(a);
        return;
    }

    vi z = z_function(b);
    int len = 0;
    for (int i = 1; i < B; ++i) {
        if (z[i] + i == B) {
            len = z[i];
            break;
        }
    }
    trace(len, z);

    // Add b[len ... B-1] into ret everytime.
    string ret = string(b);
    while (1) {
        pii memo{zeros, ones};
        for (int i = len; i < B; ++i) {
            if (b[i] == '0') {
                --zeros;
            } else {
                --ones;
            }
        }
        // We cant add b[len...B-1] as a whole string into ret;
        if (zeros < 0 || ones < 0) {
            for (int i = 0; i < memo.x; ++i) {
                ret += '0';
            }
            for (int i = 0; i < memo.y; ++i) {
                ret += '1';
            }
            break;
        }
        for (int i = len; i < B; ++i) {
            ret += b[i];
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

