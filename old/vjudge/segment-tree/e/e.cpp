//============================================================================
// Name        : e
// Date        : Wed Feb 13 13:07:29 CST 2019
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
    int lo, hi, val, mset = -1;
    int f(int a, int b) { return a + b; }

    Node (int low, int high) : lo(low), hi(high) {
        val = (hi - lo) * 1;
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
            val = f(l->val, r->val);
        }
    }

    ~Node() {
        // Prevent memory leak here.
        delete l;
        delete r;
    }

    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return f(l->query(L, R), r->query(L, R));
    }

    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x, val = (hi - lo) * x;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = f(l->val, r->val);
        }
    }

    void push() {
        if (mset != -1) {
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = -1;
        }
    }
};


int knodes;
void dfs(Node *seg) {
    if (!seg) return;
    ++knodes;
    // trace(seg->lo, seg->hi, seg->val);
    dfs(seg->l);
    dfs(seg->r);
}

void solve(int tt) {
    int n, q; cin >> n >> q;

    Node *seg = new Node(0, n);
    fori (i, 0, q) {
        int a, b, c; cin >> a >> b >> c;
        // trace(a, b, c);
        seg->set(--a, b, c);
    }

    // knodes = 0;
    // dfs(seg);
    // trace(knodes);

    cout << "Case " << tt << ": The total value of the hook is "
         << seg->query(0, n) << ".\n";

    // Free memory space
    delete seg;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    // while (1);
    return 0;
}

