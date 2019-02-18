//============================================================================
// Name        : m
// Date        : Mon Feb 18 19:25:23 CST 2019
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
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << '\n'

#ifdef TRACE
#include "debug.h"
#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    debug() << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    string name = string(names).substr(0, split - names);
    debug() << name << ": " << arg << " |";
    _f(split, args...);
}
#else
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
    int lo, hi, sum = 0, lazy = -1;
    int f(int a, int b) {
        return a + b;
    }

    Node(int b, int e) : lo(b), hi(e) {
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid + 1, hi);
            sum = f(l->sum, r->sum);
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    void set(int L, int R, int x) {
        if (R < lo || hi < L) return;
        if (L <= lo && hi <= R) {
            lazy = x, sum = (hi - lo + 1) * x;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            sum = f(l->sum, r->sum);
        }
    }

    void push() {
        if (lazy != -1) {
            l->set(lo, hi, lazy), r->set(lo, hi, lazy);
            lazy = -1;
        }
    }

    int query(int L, int R) {
        if (R < lo || hi < L) return 0;
        if (L <= lo && hi <= R) return sum;
        push();
        return f(l->query(L, R), r->query(L, R));
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Node *root = new Node(0, n - 1);
    fori (i, 0, m) {
        int op; cin >> op;
        if (op == 1) {
            int a, f; cin >> a >> f;
            int t = root->query(a, n - 1);
            if (t == n - a) {
            // Starts from `a`, all vases are full.
                output("Can not put any one.");
                continue;
            }
            // Otherwise we know, it doesnt full,
            // binary search to find the leftmost vase that is empty.
            int lo = a, hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (root->query(lo, mid) == mid - lo + 1) {
                // Left half is full, try another half.
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            cout << lo << " ";

            // Computes the number of flowers can be placed in the rest vases.
            f = min(f, n - a - t);
            // binary search to find the rightmost vase.
            lo = a, hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (mid - a + 1 >= f + root->query(a, mid)) {
                // If it ends at this position, it can hold all flowers, this
                // position can be a rightmost candidate.
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << hi << "\n";
            // trace(lo, hi);
            root->set(a, hi, 1);
        } else {
            int a, b; cin >> a >> b;
            // trace(a, b);
            output(root->query(a, b));
            root->set(a, b, 0);
        }
    }
    cout << "\n";
    delete root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

