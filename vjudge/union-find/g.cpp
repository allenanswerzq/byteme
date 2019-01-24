//============================================================================
// Name        : g
// Date        : Wed Jan 16 21:43:23 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

typedef struct Node {
    int p, d;
} Node;

struct UF {
    vi e;
    UF(int n) : e(n + 1, -1) {}

    int find(int x) {
        return e[x] < 0 ? x : find(e[x]);
    }

    void set(int t) {
        e[t] = t - 1;
    }
};

const int maxn = 1e4 + 10;
Node aa[maxn];
int n;

bool cmp(Node a, Node b) {
    return a.p > b.p;
}

void solve() {
    fori (i, 0, n) {
        cin >> aa[i].p >> aa[i].d;
    }
    sort(aa, aa + n, cmp);

    int ret = 0;
    UF uf(maxn);
    fori (i, 0, n) {
        int t = uf.find(aa[i].d);
        if (t > 0) {
            ret += aa[i].p;
            uf.set(t);
        }
    }

    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        solve();
    }
    return 0;
}
