//============================================================================
// Name        : h
// Date        : Thu Jan 17 09:40:38 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//     cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//     const char* split = strchr(names + 1, ',');
//     cout.write(names, split - names) << ": " << arg << " |";
//     _f(split, args...);
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct UF {
    vi e, val;
    UF(int n) : e(n+1, -1), val(n+1, 0) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int root = find(e[x]);
        val[x] ^= val[e[x]];
        e[x] = root;
        return root;
    }

    bool join(int u, int v, string op) {
        int t1 = find(u), t2 = find(v);
        int parity = (op == "even" ? 0 : 1);
        if (t1 == t2) {
            // val[u] denotes the parity from u to root of this set.
            // thus val[u] ^ val[v] denotes the parity in the range of (u...v]
            if ((val[u] ^ val[v]) != parity) {
                return 0;
            }
        } else {
            e[t2] = t1;
            val[t2] = val[u] ^ val[v] ^ parity;
        }
        return 1;
    }
};

const int maxn = 1e4 + 7;
int n, m;

// Because the length of the input sequence is huge(1e9) that can not
// fit into memory, but here we only need to touch a few of these sequence
// indices, thus use a hashmap to assign each a new samller index.
int tot;
map<int, int> mp;
int get(int x) {
    if (mp.count(x)) return mp[x];
    mp[x] = tot++;
    return mp[x];
}

void solve() {
    cin >> n >> m;
    tot = 0;
    int ret = 0;
    UF uf(maxn);
    fori (i, 0, m) {
        int u, v; string op;
        cin >> u >> v >> op;
        u = get(u - 1);
        v = get(v);
        if (uf.join(u, v, op)) ++ret;
        else break;
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
