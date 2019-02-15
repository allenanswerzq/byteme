//============================================================================
// Name        : b
// Date        : Thu Feb 14 20:04:41 CST 2019
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

void solve() {
    int n, m; cin >> n >> m;
    priority_queue<pii, vpii, greater<pii>> dq;

    vi aa(n, 0), cc(n, 0);
    fori (i, 0, n) {
        cin >> aa[i];
    }

    fori (i, 0, n) {
        cin >> cc[i];
        dq.push({cc[i], i});
    }

    // pvi(aa, 1);
    // pvi(cc, 1);

    fori (i, 0, m) {
        int ix, needs; cin >> ix >> needs;
        --ix;
        if (aa[ix] >= needs) {
            aa[ix] -= needs;
            output(1ll * needs * cc[ix]);
        } else {
            ll cost = 1ll * aa[ix] * cc[ix];
            needs -= aa[ix];
            aa[ix] = 0;
            bool ok = 0;
            while (sz(dq)) {
                while (sz(dq) && aa[dq.top().second] == 0) dq.pop();
                if (dq.empty()) break;
                pii tp = dq.top();
                if (needs <= aa[tp.second]) {
                    aa[tp.second] -= needs;
                    cost += 1ll * needs * tp.first;
                    ok = 1;
                    output(cost);
                    break;
                } else {
                    cost += 1ll * aa[tp.second] * tp.first;
                    needs -= aa[tp.second];
                    aa[tp.second] = 0;
                    dq.pop();
                }
            }
            if (!ok) {
                output(0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}

