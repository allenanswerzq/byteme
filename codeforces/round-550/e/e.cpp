//============================================================================
// Name        : e
// Date        : Tue Apr  2 10:59:27 CST 2019
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

vi parse(string& a) {
    vi ret(sz(a) + 1);
    for (int i = 0; i < sz(a); ++i) {
        ret[i + 1] = a[i] - 'a';
    }
    return ret;
}

void solve() {
    int n; string s, t;
    cin >> n >> s >> t;
    vi a = parse(s), b = parse(t);
    trace(a, b);
    // Base 26 addition
    int carry = 0;
    for (int i = n; i > 0; --i) {
        a[i] += b[i] + carry;
        carry = a[i] / 26;
        a[i] %= 26;
    }
    a[0] = carry;
    trace(a, b);
    // Base 26 division.
    for (int i = 0; i <= n; ++i) {
        int rem = a[i] % 2;
        a[i] /= 2;
        if (i + 1 <= n) {
            a[i + 1] += rem * 26;
        } else {
            assert(rem == 0);
        }
    }
    trace(a, b);
    string ret;
    for (int i = 1; i <= n; ++i) {
        ret += (char)(a[i] + 'a');
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

