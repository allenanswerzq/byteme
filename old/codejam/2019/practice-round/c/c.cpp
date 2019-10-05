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

const int mod = (int) 1e9 + 7;

ll mod_pow(ll x, ll y) {
    if (y == 0) return 1;
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return ret % mod;
}

void solve(int t) {
    ll N, K, x1, y1, C, D, E1, E2, F;
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;

    vector<ll> A(N + 1);
    A[1] = (x1 + y1) % F;
    fori (i, 2, N + 1) {
        ll xi = ( C * x1 + D * y1 + E1 ) % F;
        ll yi = ( D * x1 + C * y1 + E2 ) % F;
        x1 = xi, y1 = yi;
        A[i] = (xi + yi) % F;
    }

    ll power = 0;
    fori (k, 1, K + 1) {
        fori (L, 1, N + 1) {
            fori (R, L, N + 1) {
                fori (j, L, R + 1) {
                    power = (power + A[j] * mod_pow(j - L + 1, k)) % mod;
                }
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

