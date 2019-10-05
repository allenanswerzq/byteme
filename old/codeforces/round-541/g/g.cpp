//============================================================================
// Name        : g
// Date        : Thu Feb 28 16:12:07 CST 2019
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

// TODO(landcold7): Still too hard for me now, leave it for now...

struct Tree {
    typedef int T;
    static const T LOW = INT_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = 0) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos > 1; pos /= 2)
            s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = LOW, rb = LOW;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vpii> blocks(n);
    fori (i, 0, n) {
        int k; cin >> k;
        blocks[i].resize(k);
        fori (j, 0, k) {
            cin >> blocks[i][j].first;
        }
        fori (j, 0, k) {
            cin >> blocks[i][j].second;
        }
    }

    int q; cin >> q;
    vector<pair<ll, ll>> dominoes;
    fori (i, 0, q) {
        ll id, mul;
        cin >> id >> mul;
        fora (x, blocks[--id]) {
            // dominoes.pb({x.first, x.second * mul});
            dominoes.pb({x.first, x.second * mul});
        }
    }

    trace(dominoes);

    // The mostleft position that will be fell down when push `i`th
    // dominoes to the left side.
    vi fallsLeft(m);


    trace(fallsLeft);

    // The mostright position that will be fell down when push `i`th
    // dominoes to the right side.
    // vi fallsRight(m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

