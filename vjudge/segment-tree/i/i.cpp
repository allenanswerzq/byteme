//============================================================================
// Name        : i
// Date        : Thu Feb 14 16:05:35 CST 2019
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

int n, m;
void solve() {
    vi destory, stk;
    destory.pb(0), destory.pb(n + 1);
    fori (i, 0, m) {
        char op; cin >> op;
        if (op == 'D') {
            int x; cin >> x;
            stk.pb(x);
            auto it = lower_bound(all(destory), x);
            if (*it != x) {
                destory.insert(it, x);
            }
        } else if (op == 'Q') {
            int x; cin >> x;
            auto it = lower_bound(all(destory), x);
            if (*it == x) {
            // If this node is already been destoryed
                output(0);
            } else {
                output(*it - *prev(it) - 1);
            }
        } else {
            if (sz(stk)) {
                int tp = stk.back(); stk.pop_back();
                auto it = lower_bound(all(destory), tp);
                if (*it == tp) destory.erase(it);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> m) {
        solve();
    }
    return 0;
}

