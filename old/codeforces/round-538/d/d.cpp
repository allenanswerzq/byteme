//============================================================================
// Name        : d
// Date        : Sun Feb 17 12:03:10 CST 2019
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

const int maxn = 5200;
int dp[maxn][maxn][2];

void amin(int& a, int b) {
    a = min(a, b);
}

void solve() {
    int n; cin >> n;
    vi cc(n, 0);
    fori (i, 0, n) {
        cin >> cc[i];
    }

    int inf = 0x3f3f3f3f;
    fori (i, 0, n) fori (j, 0, n) {
        dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : inf);
    }

    fori (r, 0, n) ford (l, r, -1) {
        fori (k, 0, 2) {
            int c = (k == 0 ? cc[l] : cc[r]);
            if (l) {
                amin(dp[l-1][r][0], dp[l][r][k] + (c != cc[l-1]));
            }
            if (r + 1 < n) {
                amin(dp[l][r+1][1], dp[l][r][k] + (c != cc[r+1]));
            }
        }
    }

    output(min(dp[0][n-1][0], dp[0][n-1][1]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

