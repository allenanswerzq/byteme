//============================================================================
// Name        : c
// Date        : Fri Feb 15 21:10:40 CST 2019
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

int n, k, A, B;
vi cc;

int binary_search(int lo, int hi) {
    auto l = lower_bound(all(cc), lo);
    auto r = upper_bound(all(cc), hi);
    return r - l;
}

ll go(int lo, int hi) {
    int x = binary_search(lo, hi);
    // trace(lo, hi, x);
    ll cost = x == 0 ? A : 1ll * B * x * (hi - lo + 1);
    if (hi == lo || x == 0) return cost;
    int mid = lo + (hi - lo) / 2;
    ll l = go(lo, mid);
    ll h = go(mid + 1, hi);
    return min(cost, l + h);
}

void solve() {
    cin >> n >> k >> A >> B;
    fori (i, 0, k) {
        int x; cin >> x;
        cc.pb(x);
    }
    sort(all(cc));
    // pvi(cc, 1);
    ll ret = go(1, (1 << n));
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}

