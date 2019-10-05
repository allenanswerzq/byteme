//============================================================================
// Name        : c
// Date        : Tue Feb 26 09:54:15 CST 2019
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

int n;
vvi aa;
priority_queue<pii> dq;

int sym(int i) {
    return n - i - 1;
}

void put(vpii pos) {
    auto tp = dq.top(); dq.pop();
    if (tp.first < sz(pos)) {
        output("NO");
        // Terminates the whole program.
        exit(0);
    }

    fora (p, pos) {
        aa[p.first][p.second] = tp.second;
    }

    tp.first -= sz(pos);
    dq.push(tp);

}

void solve() {
    cin >> n;
    map<int, int> cnts;
    fori (i, 0, n * n) {
        int x; cin >> x;
        cnts[x]++;
    }

    fora (c, cnts) {
        dq.push({c.second, c.first});
    }

    // trace(cnts);
    aa = vvi(n, vi(n));
    int m = n / 2;
    fori (i, 0, m) {
        fori (j, 0, m) {
            put({{i, j}, {i, sym(j)}, {sym(i), j}, {sym(i), sym(j)}});
        }
    }

    if (n % 2) {
        fori (i, 0, m) {
            put({{i, m}, {sym(i), m}});
            put({{m, i}, {m, sym(i)}});
        }
        put({{m, m}});
    }

    output("YES");
    fora (a, aa) {
        par(a, 0, n, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

