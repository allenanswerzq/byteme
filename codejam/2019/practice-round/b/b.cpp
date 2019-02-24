//============================================================================
// Name        : b
// Date        : Sun Feb 24 10:19:23 CST 2019
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

// Wow, it got accepted, how so???
int go(int s, int lo, int hi, string& ss, vector<bool>& visit) {
    if (s == sz(ss)) {
        return 0;
    }
    if (visit[s]) {
        return 0;
    }
    int a, b;
    a = b = (ss[s] - '0'), visit[s] = 1;
    if (!visit[lo]) {
        visit[lo] = 1;
        a += go(s + 1, lo + 1, hi, ss, visit);
        visit[lo] = 0;
    }

    if (!visit[hi]) {
        visit[hi] = 1;
        b += go(s + 1, lo, hi - 1, ss, visit);
        visit[hi] = 0;
    }
    // trace(ss, s, lo, hi, a, b);
    return max(a, b);
}

void solve(int t) {
    int n; cin >> n;
    string ss; cin >> ss;
    assert(n == sz(ss));

    int ret = 0;
    fori (i, 0, n) {
        vector<bool> visit(n, 0);
        ret = max(ret, go(i, 0, n - 1, ss, visit));
    }
    jam(t, ret);
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

