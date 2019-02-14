//============================================================================
// Name        : g
// Date        : Wed Feb 13 21:31:28 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;

#define pb push_back
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
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

int gmi, gmx;

struct Node {
    Node *l, *r;
    int mi, mx, lo, hi;
    Node (vi& v, int b, int e) : lo(b), hi(e) {
        l = r = 0;
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            mi = min(l->mi, r->mi);
            mx = max(l->mx, r->mx);
        } else {
            mi = mx = v[lo];
        }
    }

    ~Node () {
        delete l;
        delete r;
    }

    void query(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            gmi = min(gmi, mi);
            gmx = max(gmx, mx);
        } else {
            l->query(L, R), r->query(L, R);
        }
    }
};

// void dfs(Node *root) {
//     if (!root) return;
//     trace(root->lo, root->hi, root->mi, root->mx);
//     dfs(root->l);
//     dfs(root->r);
// }

void solve() {
    int n, q; scanf("%d %d", &n, &q);
    vi aa(n, 0);
    fori (i, 0, n) {
        scanf("%d", &aa[i]);
    }

    Node *root = new Node(aa, 0, sz(aa));

    // dfs(root);

    fori (i, 0, q) {
        int a, b; scanf("%d %d", &a, &b);
        gmi = INT_MAX, gmx = INT_MIN;
        root->query(--a, b);
        // trace(a, b, gmi, gmx);
        output(gmx - gmi);
    }

    delete root;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}

