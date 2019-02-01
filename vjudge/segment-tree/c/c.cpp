//============================================================================
// Name        : c
// Date        : Thu Jan 31 11:53:03 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <limits>
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

struct Node {
    typedef ll T;
    static const T LOW = 0;
    #define UPDATE ((hi - lo) * x)
    // #define UPDATE (x)
    T f(T a, T b) { return (a + b); }

    int lo, hi;
    Node *l, *r;
    T mset, madd, val;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vector<T>& v, int lo, int hi) : lo(lo), hi(hi) {
        l = r = 0; mset = -1, madd = 0, val = LOW;
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = f(l->val, r->val);
        } else {
            val = v[lo];
        }
    }
    T query(int L, int R) {
        if (R <= lo || hi <= L) return LOW;
        if (L <= lo && hi <= R) return val;
        push();
        return f(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x, madd = 0;
            val = UPDATE;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = f(l->val, r->val);
        }
    }
    void add(int L, int R, T x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != -1) mset += x;
            else madd += x;
            val += UPDATE;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = f(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != -1) {
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -1;
        } else if (madd) {
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        }
    }
};

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    vl aa(n, 0);
    fori (i, 0, n) {
        scanf("%lld", &aa[i]);
    }

    Node* tr = new Node(aa, 0, sz(aa));

    fori (i, 0, m) {
        char ch; cin >> ch;
        if (ch == 'Q') {
            int a, b;
            scanf("%d %d", &a, &b);
            output(tr->query(--a, b));
        } else if (ch == 'C') {
            int a, b; ll c;
            scanf("%d %d %lld", &a, &b, &c);
            tr->add(--a, b, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}

