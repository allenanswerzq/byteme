//============================================================================
// Name        : a
// Date        : Wed Mar 20 14:50:42 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
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

const int inf = (int)1e6 + 7;
vi primes;
void sieve(int n) {
    primes = vi(n + 1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= n; j += i) {
            primes[j] = 0;
        }
    }
}

int cs;
void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &t : a) {
        cin >> t;
    }

    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i] + 1; j < inf; ++j) {
            if (primes[j]) {
                ret += j;
                break;
            }
        }
    }
    cout << "Case " << cs << ": " << ret << " Xukha\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(inf);

    cs = 0;
    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        ++cs;
        solve();
    }
    return 0;
}

