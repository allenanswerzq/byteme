//============================================================================
// Name        : e
// Date        : Sat Jan 26 14:41:33 CST 2019
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

const int maxn = 330;
int aa[maxn];

void solve() {
    int n, m; cin >> n >> m;
    mst(aa, 0);
    fori (i, 1, n + 1) {
        cin >> aa[i];
    }

    vpii segs; segs.pb({0, 0});
    fori (i, 0, m) {
        int a, b;
        cin >> a >> b;
        segs.pb({a, b});
    }

    // par(aa, 1, n + 1, 1);
    // fora (seg, segs) {
    //     trace(seg.first, seg.second);
    // }

    int ret = *max_element(aa + 1, aa + 1 + n) - *min_element(aa + 1, aa + 1 + n);
    vi gsub;
    fori (i, 1, n + 1) {
        vi sub, add(n + 1, 0);
        fori (j, 1, m + 1) {
            int lo = segs[j].first, hi = segs[j].second;
            if (!(lo <= i && i <= hi)) {
                sub.pb(j);
                fori (k, lo, hi + 1) {
                    --add[k];
                }
            }
        }
        int mx = numeric_limits<int>::min(), mi = numeric_limits<int>::max();
        fori (j, 1, n + 1) {
            mx = max(mx, aa[j] + add[j]);
            mi = min(mi, aa[j] + add[j]);
        }
        if (ret < mx - mi) {
            ret = mx - mi;
            gsub = sub;
        }
    }
    output(ret);
    output(sz(gsub));
    pvi(gsub, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}

