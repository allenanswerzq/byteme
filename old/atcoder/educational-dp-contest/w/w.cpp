//============================================================================
// Name        : w
// Date        : Fri Mar  8 16:51:06 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// TODO(landcold7): so hard for me right now, leave it..

struct Node {
    Node *l, *r;
    ll tr, tag;
    int lo, hi;
    Node(int b, int e) : lo(b), hi(e) {
        l = r = 0;
        tr = tag = 0;
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid + 1, hi);
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    void set(int L, int R, int x) {
        if (R < lo || hi < L) return;
        if (L <= lo && hi <= R) {
            tr += x, tag += x;
            return;
        } else {
            l->set(L, R, x), r->set(L, R, x);
            tr = max(l->tr, r->tr) + tag;
        }
    }
};

void dfs(Node *root) {
    if (!root) return;
    trace(root->lo, root->hi, root->tr, root->tag);
    dfs(root->l);
    dfs(root->r);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vpii> g(n + 1);
    fori (i, 0, m) {
        int l, r, a;
        cin >> l >> r >> a;
        g[r].pb({l, a});
    }

    Node *seg = new Node(1, n);
    fori (i, 1, n + 1) {
        seg->set(i, i, seg->tr);
        fora (v, g[i]) {
            seg->set(v.first, i, v.second);
        }
    }
    output(max(seg->tr, 0ll));
    delete seg;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

