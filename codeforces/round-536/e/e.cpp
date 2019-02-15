//============================================================================
// Name        : e
// Date        : Fri Feb 15 17:04:57 CST 2019
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

struct RedPacket {
    int d, w, t;
    bool operator< (const RedPacket& e) const {
        return w > e.w || (w == e.w && d > e.d);
    }
};

const int maxn = (int) 1e5 + 7;
vector<RedPacket> ee[maxn];
RedPacket aa[maxn];
map<RedPacket, int> mp;

ll dp[maxn][220];

void insert(RedPacket& p) {
    mp[p]++;
}

void erase(RedPacket& p) {
    if (--mp[p] == 0) {
        mp.erase(p);
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    fori (i, 0, k) {
        int s, t, d, w; cin >> s >> t >> d >> w;
        ee[s].pb({d, w, 1});
        ee[t + 1].pb({d, w, -1});
    }

    // Chose the best red packet for each time step.
    fori (i, 1, n + 1) {
        fora (p, ee[i]) {
            if (p.t == 1) insert(p);
            else erase(p);
        }
        if (sz(mp)) aa[i] = (*mp.begin()).first;
        else aa[i] = {i, 0, 0};
    }

    ll ret = numeric_limits<ll>::max();
    mst(dp, 0x3f);
    dp[1][0] = 0;
    fori (j, 0, m + 1) {
        fori (i, 1, n + 1) {
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            dp[aa[i].d + 1][j] = min(dp[aa[i].d + 1][j], dp[i][j] + aa[i].w);
        }
        ret = min(ret, dp[n+1][j]);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}

