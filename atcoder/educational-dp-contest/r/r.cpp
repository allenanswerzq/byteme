//============================================================================
// Name        : r
// Date        : Tue Mar  5 14:46:32 CST 2019
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

const int mod = (int) 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(int a, int b) {
    return (ll) a * b % mod;
}

template<class T> struct Matrix {
    typedef Matrix M;
    int N; vector<vector<T>> d;
    Matrix(int n) : N(n) {
        d = vector<vector<T>>(n, vector<T>(n, 0));
    }

    M operator* (const M& m) const {
        M a(N);
        fori (i, 0, N) {
            fori (j, 0, N) {
                fori (k, 0, N) {
                    add(a.d[i][j], mul(d[i][k], m.d[k][j]));
                }
            }
        }
        return a;
    }

    M operator^ (ll p) const {
        assert(p >= 0);
        M a(N), b(*this);
        fori(i, 0, N) {
            a.d[i][i] = 1;
        }
        while (p) {
            if (p & 1) {
                a = a * b;
            }
            b = b * b;
            p >>= 1;
        }
        return a;
    }

    // friend debugstream& operator<< (debugstream& os, Matrix<T>& m);
};

// debugstream& operator<< (debugstream& os, Matrix<int>& m) {
//     os << "Matirx(" << m.d << ")";
//     return os;
// }


void solve() {
    int n; ll k;
    cin >> n >> k;
    Matrix<int> m(n);
    fori (i, 0, n) fori (j, 0, n) {
        cin >> m.d[i][j];
    }

    m = m ^ k;

    int ret = 0;
    fori (i, 0, n) fori (j, 0, n) {
        add(ret, m.d[i][j]);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

