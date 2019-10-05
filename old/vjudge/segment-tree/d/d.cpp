
// Name        : d
// Date        : Sun Feb  3 17:10:00 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
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

struct Itv {
    int b, e;
};

struct Node {
    int lo, hi, color;
    Node *l, *r;
    int f(int a, int b) {
        if (!a && b) return b;
        else if (a && !b) return a;
        else if (a == b) return a;
        else return 0;
    }

    Node (int lo, int hi) : lo(lo), hi(hi) {
        color = 0;
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            // [lo...mid)
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        } else {
            l = r = 0;
        }
    }

    ~Node () {
        delete l;
        delete r;
    }

    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return color;
        push();
        return f(l->query(L, R), r->query(L, R));
    }

    // Sets the interval [L...R) with color `col`.
    void set(int L, int R, int col) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            color = col;
        } else {
            push(), l->set(L, R, col), r->set(L, R, col);
        }
    }

    void push() {
        if (color) {
            l->set(lo, hi, color), r->set(lo, hi, color), color = 0;
        }
    }
};

const int maxm = (int) 1e7 + 7;
const int maxn = (int) 1e4 + 7;
int ha[maxm];
int aa[maxn * 2], kcnt;
Itv posts[maxn];
bool visit[maxn];
int ret;

void query(struct Node *seg) {
    // trace("query", seg->lo, seg->hi, seg->color);
    int col = seg->color;
    if (col) {
        if (!visit[col]) {
            ++ret;
            visit[col] = 1;
        }
        return;
    }

    if (seg->lo + 1 == seg->hi) return;
    query(seg->l);
    query(seg->r);
}

// void dfs(Node *root) {
//     if (!root) return;
//     trace(root->lo, root->hi, root->color);
//     dfs(root->l);
//     dfs(root->r);
// }

void solve() {
    int n; cin >> n;
    kcnt = 0;
    mst(posts, 0);
    mst(aa, 0);
    fori (i, 0, n) {
        cin >> posts[i].b >> posts[i].e;
        aa[kcnt++] = posts[i].b;
        aa[kcnt++] = posts[i].e;
    }

    sort(aa, aa + kcnt);
    kcnt = unique(aa, aa + kcnt) - aa;
    // trace(kcnt);
    mst(ha, 0);
    fori (i, 0, kcnt) {
        ha[aa[i]] = i;
        // trace(aa[i], i);
    }

    Node *seg = new Node(0, kcnt);
    int color = 1;
    fori (i, 0, n) {
        int b = ha[posts[i].b], e = ha[posts[i].e] + 1;
        // trace(posts[i].b, posts[i].e, b, e);
        seg->set(b, e, color++);
    }

    ret = 0;
    // dfs(seg);
    mst(visit, 0);
    query(seg);
    output(ret);

    delete seg;
}

// void test() {
//     Node *seg = new Node(0, 10);
//     // [2...5] equals 1
//     seg->set(2, 6, 1);
//     // [3...7] euqals 2
//     seg->set(4, 8, 2);
//     assert(seg->query(2, 4) == 1);
//     assert(seg->query(3, 8) == 2);
//     assert(seg->query(5, 6) == 2);
//     // dfs(seg);
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // test();
    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

