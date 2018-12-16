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
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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

double tick() {
    static clock_t old;
    clock_t now = clock();
    double diff = 1.0 * (now - old);
    diff /= CLOCKS_PER_SEC;
    old = now;
    return diff;
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

// TODO: Still wrong answer
const int inf = 0x3f3f3f3f;
const int maxn = 59049; // 3**10
int edges[20][20], dp[maxn][20], stat[20];
int n, m, cnt[maxn][20], ret;

void init() {
    mst(stat, 0);
    mst(cnt, 0);

    stat[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        stat[i] = stat[i - 1] * 3;
    }

    // par(stat, n + 2, 1);

    for (int i = 1; i <= stat[n + 1]; i++) {
        int tmp = i;
        for (int j = 1; j <= n; j++) {
            cnt[i][j] = tmp % 3;
            tmp = tmp / 3;
        }
    }

    // fori (i, 1, stat[n + 1] + 1) {
    //     par(cnt[i], n + 1, 1);
    // }
}


// Given old state and source city, try to move to other cities.
void step(int old_st, int src_city) {
    fori (i, 1, n + 1) {
        if (cnt[old_st][i] < 2 && src_city != i) {
            int new_st = old_st + stat[i];
            int fee = dp[old_st][src_city] + edges[src_city][i];
            dp[new_st][i] = min(dp[new_st][i], fee);
        }
    }
}

void solve() {

    init();

    mst(edges, 0x3f);
    fori (i, 1, m + 1) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = edges[b][a] = min(edges[a][b], c);
    }


    mst(dp, 0x3f);
    fori (i, 1, n + 1) {
        dp[stat[i]][i] = 0;
    }

    ret = inf;
    fori (i, 1, stat[n + 1]) {
        int ok = 1;
        for (int j = 1; j <= n; ++j) {
            if (cnt[i][j]) {
                step(i, j);
            } else {
                ok = 0;
            }
        }

        if (ok) {
            fori (j, 1, n + 1) {
                ret = min(ret, dp[i][j]);
            }
        }
    }

    output(ret == inf ? -1 : ret);

}

int main() {
    while(cin >> n >> m) {
        solve();
    }
    return 0;
}


