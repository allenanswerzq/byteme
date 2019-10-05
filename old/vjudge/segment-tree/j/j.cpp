//============================================================================
// Name        : j
// Date        : Mon Feb 18 13:33:12 CST 2019
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
    Node *l = 0, *r = 0;
    int lo, hi, task = -1;

    Node(int b, int e) : lo(b), hi(e) {
        int mid = lo + (hi - lo) / 2;
        if (lo < hi) {
            l = new Node(lo, mid);
            r = new Node(mid + 1, hi);
        }
    }

    ~Node() {
        delete l;
        delete r;
    }

    // Set an interval
    void set(int L, int R, int x) {
        if (R < lo || hi < L) return;
        if (L <= lo && hi <= R) {
            task = x;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
        }
    }

    // Query only at a point
    int query(int x) {
        if (lo == hi && x == lo) return task;
        push();
        int mid = lo + (hi - lo) / 2;
        if (x <= mid) {
            return l->query(x);
        } else {
            return r->query(x);
        }
    }

    void push() {
        if (task != -1) {
            l->set(lo, hi, task), r->set(lo, hi, task), task = -1;
        }
    }
};

const int maxn = 50000 + 7;
int range_start[maxn];
int range_end[maxn];
bool visit[maxn];
int seq;

struct Edge {
    int to, nxt;
} edges[maxn];
int head[maxn], kedge;

void add_edge(int u, int v) {
    // trace(u, v, kedge, head[u]);
    Edge e = {v, head[u]};
    edges[kedge] = e;
    head[u] = kedge++;
}

void dfs(int u) {
    // trace(u, seq);
    range_start[u] = ++seq;
    for (int i = head[u]; i >= 0; i = edges[i].nxt) {
        dfs(edges[i].to);
    }
    range_end[u] = seq;
}

void dfs_root(Node *root) {
    if (!root) return;
    dfs_root(root->l);
    dfs_root(root->r);
}

void solve(int tt) {
    int n; cin >> n;
    mst(visit, 0);
    mst(head, -1), kedge = 0;
    fori (i, 0, n - 1) {
        int u, v; cin >> u >> v;
        visit[u] = 1;
        add_edge(v, u);
    }

    seq = 0;
    fori (i, 1, n + 1) {
        if (!visit[i]) {
            dfs(i);
            break;
        }
    }

    cout << "Case #" << tt << ":\n";
    int m; cin >> m;
    Node *root = new Node(1, seq);
    fori (i, 0, m) {
        char op; cin >> op;
        if (op == 'C') {
            int x; cin >> x;
            output(root->query(range_start[x]));
        } else {
            int x, y; cin >> x >> y;
            root->set(range_start[x], range_end[x], y);
        }
    }
    delete root;
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
