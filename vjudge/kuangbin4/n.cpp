// #include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
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

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//     cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//     const char* split = strchr(names + 1, ',');
//     cout.write(names, split - names) << ": " << arg << " |";
//     _f(split, args...);
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 107;
const int inf = (1 << 30);
vector<int> gg[maxn];
int visit[maxn];
int ret = (1 << 30);

void dfs(int src, int dst, int step) {
    if (step >= ret) {
        return;
    }

    if (src == dst) {
        ret = min(ret, step);
        return;
    }

    visit[src] = 1;
    fori (i, 0, sz(gg[src])) {
        int u = gg[src][i];
        if (!visit[u]) {
            if (i == 0) {
                dfs(u, dst, step);
            } else {
                dfs(u, dst, step + 1);
            }
        }
    }
    visit[src] = 0;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    fori (i, 1, n + 1) {
        int c; cin >> c;
        fori (j, 0, c) {
            int x; cin >> x;
            gg[i].pb(x);
        }
    }

    assert(1 <= a && a <= n);
    assert(1 <= b && b <= n);

    mst(visit, 0);
    dfs(a, b, 0);
    output(ret == inf ? -1 : ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
