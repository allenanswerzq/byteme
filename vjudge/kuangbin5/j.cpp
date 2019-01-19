//============================================================================
// Name        : j
// Date        : Fri Jan 18 14:04:14 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
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
    UF(int n) : e(n + 1, -1), val(n + 1, 0) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int root = find(e[x]);
        val[x] = (val[x] + val[e[x]]) % 2;
        e[x] = root;
        return root;
    }

    bool join(int u, int v) {
        if (u == v) return 0;
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            e[t2] = t1;
            val[t2] = (val[u] - val[v] + 1 + 2) % 2;
        } else {
            if (val[u] == val[v]) return 0;
        }
        return 1;
    }
};

void solve(int tt) {
    int n, m;
    scanf("%d %d", &n, &m);

    UF uf(n);
    bool ok = 0;
    fori (i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (!uf.join(u, v)) ok = 1;
    }

    cout << "Scenario #" << tt << ":\n";
    if (ok) {
        cout << "Suspicious bugs found!\n";
    } else {
        cout << "No suspicious bugs found!\n";
    }
    cout << "\n";
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t; scanf("%d", &t);
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}
