//============================================================================
// Name        : f
// Date        : Wed Feb 13 17:41:26 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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

struct Node {
    int lo, hi, col;
    Node *l, *r;
    Node (int b, int e) : lo(b), hi(e) {
        l = r = 0;
        col = -1;
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            col = x;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            // This interval is covered by multiple colors.
            col = -2;
        }
    }

    void push() {
        if (col >= 0) {
            l->set(lo, hi, col), r->set(lo, hi, col);
        }
    }
};

const int maxn = 8000 + 7;
int colors[maxn];
int n, prev_color;

void go(Node *root) {
    if (!root) return;
    int col = root->col;
    if (col == -1) {
        prev_color = -1;
        return;
    } else if (col != -2) {
        if (col != prev_color) {
            colors[col]++;
            prev_color = col;
        }
        // This interval is entirely been covered.
        return;
    }
    if (root->lo + 1 == root->hi) return;
    go(root->l);
    go(root->r);
}

// void dfs(Node *root) {
//     if (!root) return;
//     trace(root->lo, root->hi, root->col);
//     dfs(root->l);
//     dfs(root->r);
// }

void solve() {
    Node *root = new Node(0, maxn);
    fori (i, 0, n) {
        int a, b, c;
        cin >> a >> b >> c;
        // trace(a, b, c);
        root->set(a, b, c);
    }

    // dfs(root);

    prev_color = -1;
    mst(colors, 0);
    go(root);
    fori (i, 0, maxn) {
        if (colors[i]) {
            cout << i << " " << colors[i] << "\n";
        }
    }
    cout << "\n";
    delete root;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n) {
        solve();
    }
    return 0;
}

