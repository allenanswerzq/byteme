//============================================================================
// Name        : a
// Date        : Mon Jan 28 14:27:08 CST 2019
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
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
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

struct SegmentTree {
    typedef int T;
    const T LOW = 0;
    T f(T a, T b) {
        return (a + b);
    }

    int n; vector<T> s;

    SegmentTree(int n = 0, T def = 0) : n(n), s(2 * n, def) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos > 1; pos /= 2) {
            s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
        }
    }

    T query(int b, int e) {
        T ra = LOW, rb = LOW;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

const int maxn = (int) 5e4 + 7;
int aa[maxn];

void solve(int tt) {
    int n; cin >> n;
    mst(aa, 0);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    cout << "Case " << tt << ":\n";

    SegmentTree seg(n);
    fori (i, 0, n) {
        seg.update(i, aa[i]);
    }

    string op; cin >> op;
    while (op != "End") {
        int k, v; cin >> k >> v;
        if (op == "Add") {
            aa[--k] += v;
            seg.update(k, aa[k]);
        } else if (op == "Sub") {
            aa[--k] -= v;
            seg.update(k, aa[k]);
        } else if (op == "Query") {
            int r = seg.query(--k, v);
            output(r);
        }
        cin >> op;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}

