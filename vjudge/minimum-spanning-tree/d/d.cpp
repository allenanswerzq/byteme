//============================================================================
// Name        : d
// Date        : Tue Jan 22 19:24:08 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

#define pb push_back
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << '\n'
#define par(x, s, n, v) if(v) pvar(x); fori(a, s, n) prt(x, a, n) cout << '\n'

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

const int maxn = 120;
int gg[maxn][maxn];
int visit[maxn];
int n;
void prim() {
    mst(visit, 0);
    multiset<pii> dq;
    dq.insert({0, 1});
    int ret = 0;
    while (sz(dq)) {
        pii p = *dq.begin(); dq.erase(dq.begin());
        int u = p.second, w = p.first;
        if (visit[u]) continue;
        visit[u] = 1;
        ret += w;
        fori (v, 1, n + 1) {
            if (!visit[v]) {
                dq.insert({gg[u][v], v});
            }
        }
    }
    output(ret);
}

void solve() {
    cin >> n;
    fori (i, 1, n + 1) fori (j, 1, n + 1) {
        int x; cin >> x;
        gg[i][j] = x;
    }

    int q; cin >> q;
    fori (i, 0, q) {
        int u, v;
        cin >> u >> v;
        gg[u][v] = gg[v][u] = 0;
    }

    prim();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

