//============================================================================
// Name        : e
// Date        : Wed Jan 16 13:37:53 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
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
    int count, n;
    UF(int n) : e(n + 1, -1), val(n + 1, 0), count(0), n(n) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int parent = find(e[x]);
        val[x] += val[e[x]];
        val[x] %= 3;
        e[x] = parent;
        return parent;
    }

    int answer() {
        return count;
    }

    void join(int op, int x, int y) {
        if (x > n || y > n) {
            ++count;
            return;
        }
        int t1 = find(x), t2 = find(y);
        if (t1 == t2) {
            if (op == 1) {
                if (val[x] != val[y]) ++count;
            } else if (op == 2) {
                if ((val[x] + 1) % 3 != val[y]) ++count;
            }
        } else {
            if (op == 1) {
                // x and y are the same kind animal.
                e[t2] = t1;
                val[t2] = val[x] - val[y];
                val[t2] = (val[t2] + 3) % 3;
            } else {
                // x can eat y: x + 1 = y
                e[t2] = t1;
                val[t2] = val[x] - val[y] + 1;
                val[t2] = (val[t2] + 3) % 3;
            }
        }
    }
};

void solve() {
    int n, k; scanf("%d %d", &n, &k);
    UF uf(n);
    fori (i, 0, k) {
        int t, x, y; scanf("%d %d %d", &t, &x, &y);
        uf.join(t, x, y);
    }
    output(uf.answer());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
