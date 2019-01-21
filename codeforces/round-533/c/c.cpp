//============================================================================
// Name        : c
// Date        : Mon Jan 21 09:31:36 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
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

const int maxn = (int) 2e5 + 7;
const int mod = (int) 1e9 + 7;

ll dp[maxn][3], cnt[3];

void add(ll &a, ll b) {
    a = (a + b) % mod;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    --l;
    fori (i, 0, 3) {
        // f(l, r) = f(1, r) - f(1, (l-1))
        cnt[i] = (r - i + 3) / 3 - (l - i + 3) / 3;
    }

    // dp[i][j] denotes the sum of first i numbers modulo 3 is j.
    dp[0][0] = 1;
    fori (i, 0, n) {
        fori (j, 0, 3) {
            fori (k, 0, 3) {
                add(dp[i + 1][(j + k) % 3], dp[i][j] * cnt[k]);
            }
        }
    }

    output(dp[n][0]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

