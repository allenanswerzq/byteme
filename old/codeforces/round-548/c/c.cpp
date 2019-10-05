//============================================================================
// Name        : c
// Date        : Fri Mar 22 19:46:23 CST 2019
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

const int mod = (int)1e9 + 7;

ll modpow(ll x, ll y) {
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

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return -e[find(x)];
    }

    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return;
        }
        if (e[a] > e[b]) {
            swap(a, b);
        }
        e[a] += e[b];
        e[b] = a;
    }
};

vvi g;
void solve() {
    int n, k;
    cin >> n >> k;
    g = vvi(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        if (c == 0) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    // trace(g);
    UF uf(n);
    for (int u = 0; u < n; ++u) {
        for (auto v : g[u]) {
            if (v != u) {
                uf.join(v, u);
            }
        }
    }

    set<int> st;
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        int root = uf.find(i);
        if (!st.count(root)) {
            st.insert(root);
            ret += modpow(uf.size(i), k);
            ret %= mod;
        }
    }
    ret = modpow(n, k) - ret;
    if (ret < 0) {
        ret += mod;
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

