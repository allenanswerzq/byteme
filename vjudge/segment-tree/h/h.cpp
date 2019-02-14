//============================================================================
// Name        : h
// Date        : Thu Feb 14 09:57:20 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
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

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

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
    Node *l = 0, *r = 0;
    int lo, hi;
    ll val;
    ll f(ll a, ll b) { return a + b; }
    Node (vl& v, int b, int e) : lo(b), hi(e) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = f(l->val, r->val);
        } else {
            val = v[lo];
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    void update(int L, int R) {
        // If this interval's sum equals `hi - lo`, nothing to do.
        if (R <= lo || hi <= L || (val == hi - lo)) return;
        if (lo + 1 == hi) {
            val = sqrt(val * 1.0);
        } else {
            l->update(L, R);
            r->update(L, R);
            val = f(l->val, r->val);
        }
    }

    ll query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        return f(l->query(L, R), r->query(L, R));
    }

};

void dfs(Node *root) {
    if (!root) return;
    trace(root->lo, root->hi, root->val);
    dfs(root->l);
    dfs(root->r);
}

int n;
void solve(int tt) {
    vl aa(n, 0);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    cout << "Case #" << tt << ":\n";

    Node *root = new Node(aa, 0, sz(aa));

    int q; cin >> q;
    fori (i, 0, q) {
        int op, b, e;
        cin >> op >> b >> e;
        if (b > e) swap(b, e);
        if (op == 0) {
            root->update(--b, e);
        } else {
            output(root->query(--b, e));
        }
    }
    cout << "\n";
    delete root;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 0;
    while (cin >> n) {
        solve(++tt);
    }
    return 0;
}

