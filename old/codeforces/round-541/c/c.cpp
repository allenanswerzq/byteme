//============================================================================
// Name        : c
// Date        : Wed Feb 27 14:50:12 CST 2019
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

void solve2() {
    int n; cin >> n;
    vi aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    sort(all(aa));

    vi bb(n);
    int k = 0;
    for (int i = 0; i < n; i += 2) {
        bb[k++] = aa[i];
    }

    k = n - 1;
    for (int i = 1; i < n; i += 2) {
        bb[k--] = aa[i];
    }
    assert(k == (n - 1) / 2);
    par(bb, 0, n, 0);
}

void solve() {
    int n; cin >> n;
    vi aa(n);
    fori (i, 0, n) {
        cin >> aa[i];
    }
    sort(all(aa));
    deque<int> dq;
    fori (i, 0, n) {
        if (i % 2) dq.push_back(aa[i]);
        else dq.push_front(aa[i]);
    }
    par(dq, 0, n, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

