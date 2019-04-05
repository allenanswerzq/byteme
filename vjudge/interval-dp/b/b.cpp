//============================================================================
// Name        : b
// Date        : Fri Apr  5 21:16:40 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 120;
string s;
int dp[maxn][maxn];

bool check(char a, char b) {
    if (a == '(' && b == ')') {
        return 1;
    } else if (a == '[' && b == ']') {
        return 1;
    } else {
        return 0;
    }
}

int rec(int lo, int hi) {
    int& ret = dp[lo][hi];
    if (ret != -1) {
        return ret;
    }
    if (lo >= hi) {
        return ret = 0;
    }
    if (lo + 1 == hi) {
        if (check(s[lo], s[hi])) {
            return ret = 2;
        } else {
            return ret = 0;
        }
    }
    ret = rec(lo + 1, hi);
    for (int i = lo + 1; i <= hi; ++i) {
        if (check(s[lo], s[i])) {
            amax(ret, rec(lo + 1, i - 1) + rec(i + 1, hi) + 2);
        }
    }
    return ret = dp[lo][hi];
}

void solve() {
    mst(dp, -1);
    output(rec(0, sz(s) - 1));
}

void solve2() {
    int n = sz(s);
    vvi dp(n + 1, vi(n + 1, 0));
    for (int L = n - 2; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            dp[L][R] = dp[L + 1][R];
            for (int k = L + 1; k <= R; ++k) {
                if (check(s[L], s[k])) {
                    amax(dp[L][R], dp[L + 1][k - 1] + dp[k + 1][R] + 2);
                }
            }
        }
    }
    output(dp[0][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s && s != "end") {
        solve2();
    }
    return 0;
}

