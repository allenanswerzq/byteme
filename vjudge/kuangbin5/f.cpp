//============================================================================
// Name        : f
// Date        : Wed Jan 16 16:13:58 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
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

struct UF {
    // Join all those nodes that have relations into a set, one node
    // can be the same kind with root(good or bad), or can be
    // the oppisite with root.
    vi e, val;
    UF(int n) : e(n + 1, -1), val(n + 1, 0) {}

    int find(int x) {
        if (e[x] == -1) return x;
        int parent = find(e[x]);
        val[x] += val[e[x]];
        val[x] %= 2;
        e[x] = parent;
        return parent;
    }

    void join(int u, int v, string op) {
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            int x = (op == "yes" ? 0 : 1);
            e[t1] = t2;
            val[t1] = (val[v] - val[u] + x + 2) % 2;
            // e[t2] = t1;
            // val[t2] = (val[u] - val[v] + x + 2) % 2;
        }
    }

    int get(int x) {
        return val[x];
    }
};

const int maxn = 620;
// Stores members for each set.
// Each set contains two opposite parts, both can be good or bad under
// this problem's context.
vi grps[maxn][2];
// Stores the size of each set.
int grpsz[maxn][2];

int dp[maxn][maxn / 2];
int pre[maxn][maxn / 2];
bool visit[maxn];

int n, p1, p2;
void solve() {
    UF uf(p1 + p2);
    fori (i, 0, n) {
        int u, v; string op; cin >> u >> v >> op;
        uf.join(u, v, op);
    }

    mst(visit, 0);
    fori (i, 0, maxn) {
        grps[i][0].clear();
        grps[i][1].clear();
        grpsz[i][0] = 0;
        grpsz[i][1] = 0;
    }

    int kset = 1;
    fori (i, 1, p1 + p2 + 1) {
        if (visit[i] == 0) {
            int root = uf.find(i);
            fori (j, i, p1 + p2 + 1) {
                if (uf.find(j) == root) {
                    visit[j] = 1;
                    int part = uf.get(j);
                    grps[kset][part].pb(j);
                    grpsz[kset][part]++;
                }
            }
            kset++;
        }
    }

    mst(dp, 0);
    dp[0][0] = 1;
    fori (i, 1, kset) {
        ford (j, p1, -1) {
            int num = j - grpsz[i][0];
            if (num >= 0 && dp[i-1][num]) {
                dp[i][j] += dp[i-1][num];
                pre[i][j] = num;
            }

            num = j - grpsz[i][1];
            if (num >= 0 && dp[i-1][num]) {
                dp[i][j] += dp[i-1][num];
                pre[i][j] = num;
            }
        }
    }

    if (dp[kset-1][p1] != 1) {
        output("no");
    } else {
        vi ret;
        int t = p1;
        ford (i, kset - 1, 0) {
            int cur = t - pre[i][t];
            if (cur == grpsz[i][0]) {
                fori (j, 0, grpsz[i][0]) {
                    ret.pb(grps[i][0][j]);
                }
            } else {
                fori (j, 0, grpsz[i][1]) {
                    ret.pb(grps[i][1][j]);
                }
            }
            t = pre[i][t];
        }
        sort(all(ret));
        fori (i, 0, sz(ret)) {
            output(ret[i]);
        }
        output("end");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> p1 >> p2) {
        if (!n && !p1 && !p2) break;
        solve();
    }
    return 0;
}
