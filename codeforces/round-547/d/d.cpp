//============================================================================
// Name        : d
// Date        : Wed Mar 20 22:01:35 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

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

void solve() {
    int n; string a, b;
    cin >> n >> a >> b;

    map<char, vi> ca, cb;
    set<int> sa, sb;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '?') {
            sa.insert(i + 1);
        } else {
            ca[a[i]].pb(i + 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] == '?') {
            sb.insert(i + 1);
        } else {
            cb[b[i]].pb(i + 1);
        }
    }

    // trace(ca, cb);
    int ret = 0;
    vpii ps;
    set<char> visit;
    for (auto it : ca) {
        // trace(it.x, it.y);
        if (cb.count(it.x)) {
            visit.insert(it.x);
            vi va = it.y, vb = cb[it.x];
            int A = sz(va), B = sz(vb);
            if (A < B) {
                int x = min(sz(sa), B - A);
                A += x;
                vi tt = vi(all(sa));
                for (int i = 0; i < x; ++i) {
                    va.pb(tt[i]);
                }
                for (int i = 0; i < x; ++i) {
                    sa.erase(sa.begin());
                }
            } else if (B < A) {
                int x = min(sz(sb), A - B);
                B += x;
                vi tt = vi(all(sb));
                for (int i = 0; i < x; ++i) {
                    vb.pb(tt[i]);
                }
                for (int i = 0; i < x; ++i) {
                    sb.erase(sb.begin());
                }
            }
            int mi = min(A, B);
            ret += mi;
            for (int k = 0; k < mi; ++k) {
                ps.pb({va[k], vb[k]});
            }
        } else if (sz(sb)) {
            vi va = it.y;
            int mi = min(sz(va), sz(sb));
            ret += mi;
            vi tt = vi(all(sb));
            for (int i = 0; i < mi; ++i) {
                ps.pb({va[i], tt[i]});
            }
            for (int i = 0; i < mi; ++i) {
                sb.erase(sb.begin());
            }
        }
    }

    for (auto it : cb) {
        if (!visit.count(it.x) && sz(sa)) {
            vi vb = it.y;
            int mi = min(sz(vb), sz(sa));
            ret += mi;
            vi tt = vi(all(sa));
            for (int i = 0; i < mi; ++i) {
                ps.pb({tt[i], vb[i]});
            }
            for (int i = 0; i < mi; ++i) {
                sa.erase(sa.begin());
            }
        }
    }

    // trace(sa, sb);
    if (sz(sa) && sz(sb)) {
        int mi = min(sz(sa), sz(sb));
        ret += mi;
        vi va = vi(all(sa)), vb = vi(all(sb));
        for (int i = 0; i < mi; ++i) {
            ps.pb({va[i], vb[i]});
        }
    }

    output(ret);
    for (auto it : ps) {
        cout << it.x << " " << it.y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

