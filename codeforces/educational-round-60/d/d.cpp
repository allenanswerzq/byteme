//============================================================================
// Name        : d
// Date        : Mon Feb 25 15:54:35 CST 2019
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

const int mod = (int) 1e9 + 7;

template<class T> struct Matrix {
    typedef Matrix M;
    int N; vector<vector<T>> d;
    Matrix(int n) : N(n) {
        d.resize(n, vector<T>(n, 0));
    }

    Matrix(vector<vector<T>>&& v) : d(std::move(v)) {
        N = d.size();
    }

    M operator* (const M& m) const {
        M a(N);
        fori (i, 0, N) {
            fori (j, 0, N) {
                fori (k, 0, N) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                    if (a.d[i][j] >= mod) {
                        a.d[i][j] %= mod;
                    }
                }
            }
        }
        return a;
    }

    vector<T> operator* (const vector<T>& vec) const {
        vector<T> ret(N);
        fori (i, 0, N) {
            fori (j, 0, N) {
                ret[i] += d[i][j] * vec[j];
                if (ret[i] >= mod) {
                    ret[i] %= mod;
                }
            }
        }
        return ret;
    }

    M operator^ (ll p) const {
        assert(p >= 0);
        M a(N), b(*this);
        fori (i, 0, N) {
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

// http://fusharblog.com/solving-linear-recurrence-for-programming-contest/

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n < m) {
        output(1);
        return;
    }

    vl f1(m);
    fori (i, 0, m) {
        f1[i] = (i == m - 1 ? 2 : 1);
    }

    vector<vl> v(m, vl(m));
    v[m - 1][0] = 1;
    v[m - 1][m - 1] = 1;
    fori (i, 0, m - 1) {
        v[i][i + 1] = 1;
    }

    Matrix<ll> t(move(v));
    vl res = (t ^ (n - 1)) * f1;
    output(res[0]);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

