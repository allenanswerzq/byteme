//============================================================================
// Name        : q
// Date        : Mon Mar  4 22:28:40 CST 2019
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

// one-index based bit tree.
template <class T>
struct Bit {
    vector<T> x;
    Bit(int n) : x(n + 1) {}

    void add(int k, T a) {
        for (; k < sz(x); k += (k & -k)) {
            x[k] = max(x[k], a);
        }
    }

    // query [1...k]
    T query(int k) {
        T s = 0;
        for (; k > 0; k -= (k & -k)) {
            s = max(s, x[k]);
        }
        return s;
    }
};


void solve() {
    int n; cin >> n;
    vi h(n), a(n);
    fori (i, 0, n) {
        cin >> h[i];
    }

    fori (i, 0, n) {
        cin >> a[i];
    }

    Bit<ll> bit(n);
    vl dp(n);
    fori (i, 0, n) {
        // Query maximum value in range [1...h[i]], if we found one,
        // there must have h[i] > h[j] (j < i) satisfied.
        dp[i] += bit.query(h[i]) + a[i];
        bit.add(h[i], dp[i]);
    }

    // trace(h, a, dp);
    output(bit.query(n));
}

void test() {
    Bit<int> bit(5);
    vi aa = {1, 2, 3, 4, 5};
    bit.add(1, 1);
    bit.add(2, 2);
    bit.add(3, 3);
    bit.add(5, 5);
    trace(bit.query(1));
    trace(bit.query(2));
    trace(bit.query(3));
    trace(bit.query(5));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    // test();
    return 0;
}

