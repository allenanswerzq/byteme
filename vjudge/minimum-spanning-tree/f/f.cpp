//============================================================================
// Name        : f
// Date        : Tue Jan 22 21:45:37 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
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

const int maxn = 2020;
const int inf = 0x3f3f3f3f;
char ss[maxn][8];
int gg[maxn][maxn];
int visit[maxn];
int dist[maxn];
int n;

void prim() {
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
        visit[i] = 0;
    }

    dist[0] = 0;
    int res = 0;
    while (1) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visit[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        if (u == -1) break;
        visit[u] = 1;
        res += dist[u];
        for (int v = 0; v < n; v++) {
            dist[v] = min(dist[v], gg[u][v]);
        }
    }
    cout << "The highest possible quality is 1/" << res << ".\n";
}

int cost(char *a, char *b) {
    int ret = 0;
    fori (i, 0, 7) {
        if (a[i] != b[i]) {
            ++ret;
        }
    }
    return ret;
}

void solve() {
    fori (i, 0, n) {
        // cin >> ss[i];
        scanf("%s", (char*)(ss + i));
    }

    mst(gg, 0);
    fori (i, 0, n) fori (j, i + 1, n) {
        gg[i][j] = gg[j][i] = cost(ss[i], ss[j]);
    }
    prim();
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

