//============================================================================
// Name        : b
// Date        : Sun Jan 20 13:42:03 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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

struct Interval {
    int l, r;
    bool operator== (const Interval& b) const {
        return l == b.l && r == b.r;
    }
};

bool cmp(const Interval& a, const Interval& b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r > b.r;
}

int containedIntervals(vector<Interval>& aa) {
    sort(all(aa), cmp);

    int mx = numeric_limits<int>::min();
    int ret = 0, n = sz(aa);
    fori (i, 0, n) {
        if (aa[i].r <= mx || (i + 1 < n && aa[i] == aa[i + 1])) {
            ++ret;
        }
        mx = max(mx, aa[i].r);
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<Interval> aa;
    fori (i, 0, n) {
        int a, b; cin >> a >> b;
        aa.pb({a, b});
    }
    int ret = containedIntervals(aa);
    output(ret);
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    solve();
    return 0;
}

