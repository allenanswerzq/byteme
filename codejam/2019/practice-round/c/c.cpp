//============================================================================
// Name        : c
// Date        : Sun Feb 24 11:43:11 CST 2019
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

typedef unsigned long long ull;
const int bits = 1;
// if all numbers are less than 2^k, set bits = 64-k
const ull po = 1 << bits;
ull mod_mul(ull a, ull b, ull &c) {
    ull x = a * (b & (po - 1)) % c;
    while ((b >>= bits) > 0) {
        a = (a << bits) % c;
        x += (a * (b & (po - 1))) % c;
    }
    return x % c;
}

ull mod_pow(ull a, ull b, ull mod) {
    if (b == 0) return 1;
    ull res = mod_pow(a, b / 2, mod);
    res = mod_mul(res, res, mod);
    if (b & 1) return mod_mul(res, a, mod);
    return res;
}

const int mod = (int) 1e9 + 7;
void add(ull& a, ull b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve(int t) {
    int N, K, x1, y1, C, D, E1, E2, F;
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;

    vector<ull> A(N + 1);
    A[1] = (x1 + y1);
    fori (i, 2, N + 1) {
        int xi = ( 1ll * C * x1 + 1ll * D * y1 + E1 ) % F;
        int yi = ( 1ll * D * x1 + 1ll * C * y1 + E2 ) % F;
        x1 = xi, y1 = yi;
        A[i] = (xi + yi) % F;
    }

    ull power = 0;
    fori (k, 1, K + 1) {
        fori (i, 1, N + 1) fori (j, i, N + 1) {
            int c = 1;
            fori (h, i, j + 1) {
                // power %= mod;
                assert(power < mod);
                add(power, (A[h] * mod_pow(c++, k, mod)) % mod);
            }
        }
    }
    jam(t, power);
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

