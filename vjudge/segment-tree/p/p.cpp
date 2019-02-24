//============================================================================
// Name        : p
// Date        : Sun Feb 24 19:59:57 CST 2019
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
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"

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

// TODO(landcold7): Kind hard for me right now, just leave it.
struct Seg {
// An vertical line following the y axis.
    // The coordinates of this line.
    double y2, y1, x;
    // Whether this is a left edge or r edge of a rectangle.
    int f;
    Seg(double b, double e, double x, int f)
        : y2(b), y1(e), x(x), f(f) {}

    Seg() : y2(0), y1(0), x(0), f(0) {}

    bool operator< (const Seg& b) const {
        return x < b.x;
    }

    friend ostream& operator<< (ostream& os, Seg& b);
};

ostream& operator<< (ostream& os, Seg& b) {
    os << "Seg(" << b.y2 << " " << b.y1 << " "
       << b.x << " " << b.f << ")";
    return os;
}

vector<double> ypts;
struct Node {
    Node *l, *r;
    int lo, hi, ovlap;
    double sum, sum2;
    Node(vector<double>& v, int b, int e) : lo(b), hi(e) {
        l = r = nullptr;
        ypts = v;
        ovlap = sum = sum2 = 0;
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid + 1, hi);
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    void compute_sum() {
        if (ovlap) {
            sum = ypts[hi + 1] - ypts[lo];
        } else if (lo == hi) {
            sum = 0;
        } else {
            sum = l->sum + r->sum;
        }

        if (ovlap >= 2) {
            sum2 = ypts[hi + 1] - ypts[lo];
        } else if (l == r) {
            sum2 = 0;
        } else if (ovlap == 1) {
            sum2 = l->sum + r->sum;
        } else if (ovlap == 0) {
            sum2 = l->sum2 + r->sum2;
        }
    }

    void set(int L, int R, int ov) {
        if (R < lo || hi < L) return;
        if (L <= lo && hi <= R) {
            ovlap += ov;
            compute_sum();
            return;
        } else {
            l->set(L, R, ov);
            r->set(L, R, ov);
            compute_sum();
        }
    }
};

void dfs(Node* root) {
    if (!root) {
        return;
    }
    trace(root->lo, root->hi, root->ovlap, root->sum);
    dfs(root->l);
    dfs(root->r);
}

// Binary search on float numbers.
int binary_search(vector<double>& v, double x) {
    int lo = -1, hi = sz(v) - 1;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] - x >= 0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

void solve() {
    int n; cin >> n;
    vector<Seg> segs(2 * n);
    // vector<double> ypts(2 * n);
    ypts.resize(2 * n);

    int k = 0;
    fori (i, 0, n) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segs[k] = Seg(y2, y1, x1, 1);
        ypts[k++] = y1;
        segs[k] = Seg(y2, y1, x2, -1);
        ypts[k++] = y2;
    }

    sort(all(segs));
    sort(all(ypts));
    ypts.erase(unique(all(ypts)), ypts.end());
    trace(n, ypts, segs);

    Node *root = new Node(ypts, 0, sz(ypts) - 1);
    double ret = 0;
    fori (i, 0, k - 1) {
        int y1 = binary_search(ypts, segs[i].y1);
        int y2 = binary_search(ypts, segs[i].y2) - 1;
        int f = segs[i].f;
        assert(y1 <= y2);
        trace(y1, y2, f, segs[i]);
        root->set(y1, y2, f);
        ret += root->sum2 * (segs[i + 1].x - segs[i].x);
    }
    output(ret);
    delete root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;
    int t; cin >> t >> ws;
    fori (i, 0, t) {
        solve();
    }
    return 0;
}

