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

const int maxn = 1e5 + 7;
vi tree[maxn];
int sum[maxn];
int val[maxn];
ll ret;

// Note: read problem statement carefully.

// This case never occur, because the statement says
// `erased all values S𝑣 for vertices with even depth`
// 3
// 1 2
// 2 -1 -1

bool dfs(int u, int par = 0) {
    if (sum[u] == -1) {
        if (sz(tree[u]) == 0) {
            sum[u] = sum[par];
            val[u] = 0;
        } else {
            int mi = (1 << 30);
            fora (v, tree[u]) {
                mi = min(sum[v], mi);
            }

            // trace(u, par, mi);

            if (sum[par] > mi) {
                return 0;
            }
            val[u] = mi - sum[par];
            sum[u] = mi;
        }

    } else {
        val[u] = sum[u] - sum[par];
    }

    ret += val[u];
    fora (v, tree[u]) {
        if (!dfs(v, u)) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int n; cin >> n;
    fori (i, 2, n + 1) {
        int u; cin >> u;
        // u --> i
        tree[u].pb(i);
    }

    fori (i, 1, n + 1) {
        int s; cin >> s;
        sum[i] = s;
    }

    ret = 0;
    if (dfs(1, 0)) {
        output(ret);
    } else {
        output(-1);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
