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

const int b[6] = {1, 2, 4, 8, 16, 32};

int n, m;
bool can[32][32];
int dp[1001][32];

bool check(int x, int y) {
    // For each column, check if it can fit given the states (x, y) bewteen
    // two adjcent lines.

    // [0, 0] for a 1 x 2 block.

    // [1] for a 2 x 1 block.
    // [0]

    bool last = false;
    for (int k = 0; k < m; ++k) {
        if (x & b[k]) {
            if (last || (y & b[k])) {
                return false;
            }
        } else if ((y & b[k]) && last) {
            return false;
        }

        if ((y & b[k]) == 0) {
            if (x & b[k]) {
                last = false;
            } else {
                last = !last;
            }
        }
    }
    return !last;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < b[m]; ++i) {
        for (int j = 0; j < b[m]; ++j) {
            can[i][j] = check(i, j);
        }
    }

    mst(dp, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < b[m]; ++j)
            for (int k = 0; k < b[m]; ++k)
                if (can[j][k]) {
                    dp[i][k] = (dp[i - 1][j] + dp[i][k]) % 1000000007;
                }
    cout << dp[n][0] << endl;
}

