//============================================================================
// Name        : e
// Date        : Mon Feb 25 20:31:46 CST 2019
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
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << "\n"
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

void solve() {
    string t; cin >> t;
    int n = t.size();
    string s1(n, 'a'), s2(n, 'a'), s3(n, 'a');
    for (int i = 0; i < n; i++) {
        s1[i] = char('a' + (i % 26));
        s2[i] = char('a' + ((i / 26) % 26));
        s3[i] = char('a' + ((i / 26 / 26) % 26));
    }
    string t1, t2, t3;
    cout << "? " << s1 << endl; cin >> t1;
    cout << "? " << s2 << endl; cin >> t2;
    cout << "? " << s3 << endl; cin >> t3;
    vi p(n);
    fori (i, 0, n) {
        p[i] = (t1[i] - 'a') + (t2[i] - 'a') * 26 + (t3[i] - 'a') * 26 * 26;
    }

    string ret(n, 'a');
    fori (i, 0, n) {
        ret[p[i]] = t[i];
    }
    cout << "! " << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

