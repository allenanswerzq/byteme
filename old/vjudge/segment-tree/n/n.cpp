//============================================================================
// Name        : n
// Date        : Tue Feb 19 10:42:12 CST 2019
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
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << "\n"
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef TRACE
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Node {
    Node *l = nullptr, *r = nullptr;
    int lo, hi;
    int lsum, rsum, msum, lazy = -1;

    void up() {
        lsum = l->lsum;
        int mid = lo + (hi - lo) / 2;
        if (lsum == mid - lo + 1) {
            lsum += r->lsum;
        }
        rsum = r->rsum;
        if (rsum == hi - mid) {
            rsum += l->rsum;
        }
        // Note: here must be written this way.
        msum = max(l->msum, r->msum);
        msum = max(msum, l->rsum + r->lsum);
    }

    Node(int b, int e) : lo(b), hi(e) {
    // After created, the interval represented by this node is free to use.
        lsum = rsum = msum = hi - lo + 1;
        int mid = lo + (hi - lo) / 2;
        if (lo < hi) {
            l = new Node(lo, mid);
            r = new Node(mid + 1, hi);
            up();
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    // Sets an interval `[L...R]`
    void set(int L, int R, int x) {
        if (R < lo || hi < L) return;
        if (L <= lo && hi <= R) {
        // Sets `1` will occupy this interval,
        // Sets `0` will free this interval.
            lsum = rsum = msum = (x == 1 ? 0 : hi - lo + 1);
            lazy = x;
        } else {
            down(), l->set(L, R, x), r->set(L, R, x);
            up();
        }
    }

    // Queries a free interval with lenght of x.
    int query(int x) {
        // trace("query", lo, hi, x, lsum, rsum, msum);
        if (x > msum) {
        // If this interval doesn't have needed free space.
            return 0;
        }

        if (lo == hi) {
        // If reaches to the lowest node on this tree.
            return lo;
        }

        down();

        int mid = lo + (hi - lo) / 2;
        if (l->msum >= x) {
        // If the left child has the needed space, according to first
        // come first sever algorithm, choose left to query.
            return l->query(x);
        } else if (l->rsum + r->lsum >= x) {
            return mid - l->rsum + 1;
        } else {
            return r->query(x);
        }
    }

    void down() {
        if (lazy != -1) {
            l->set(lo, hi, lazy), r->set(lo, hi, lazy), lazy = -1;
        }
    }
};

void dfs(Node *root) {
    if (!root) return;
    trace(root->lo, root->hi, root->lsum, root->rsum, root->msum, root->lazy);
    dfs(root->l);
    dfs(root->r);
}

void solve(int tt) {
    int n, m;
    cin >> n >> m;
    Node *rootd = new Node(1, n);
    Node *rootn = new Node(1, n);
    cout << "Case " << tt << ":\n";
    fori (i, 0, m) {
        string op; cin >> op;
        if (op == "DS") {
            int qt; cin >> qt;
            // dfs(rootd);
            int x = rootd->query(qt);
            trace("ds", qt, x);
            if (x) {
                cout << x << ",let's fly\n";
                rootd->set(x, x + qt - 1, 1);
            } else {
                cout << "fly with yourself\n";
            }
        } else if (op == "NS") {
            int qt; cin >> qt;
            // Try query on the `rootd` tree first,
            int x = rootd->query(qt);
            if (x) {
                cout << x << ",don't put my gezi\n";
                rootd->set(x, x + qt - 1, 1);
                rootn->set(x, x + qt - 1, 1);
            } else {
            // If not find, then cancle all ds appointments,
            // equivalently means query on the `rootn` tree.
                x = rootn->query(qt);
                if (x) {
                    cout << x << ",don't put my gezi\n";
                    rootd->set(x, x + qt - 1, 1);
                    rootn->set(x, x + qt - 1, 1);
                } else {
                    cout << "wait for me\n";
                }
            }
        } else {
            int b, e; cin >> b >> e;
            rootd->set(b, e, 0);
            rootn->set(b, e, 0);
            output("I am the hope of chinese chengxuyuan!!");
        }
    }
    delete rootd;
    delete rootn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}

