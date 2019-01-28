//============================================================================
// Name        : c
// Date        : Mon Jan 28 11:18:04 CST 2019
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

const int maxn = 400;
int dp[maxn], need[maxn];

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        mst(need, 0);
        fora (d, days) {
            need[d] = 1;
        }

        mst(dp, 0x3f);
        dp[0] = 0;
        fori (i, 1, 366) {
            if (need[i] == 0) {
                dp[i] = dp[i - 1];
            }
            dp[i] = min(dp[i], dp[max(0, i - 1)] + costs[0]);
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
        }
        return dp[365];
    }
};

void test(vi days, vi costs) {
    Solution go;
    int r = go.mincostTickets(days, costs);
    output(r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    test({1, 4, 6, 7, 8, 20}, {2, 7, 15});
    test({1,2,3,4,5,6,7,8,9,10,30,31}, {2, 7, 15});
    return 0;
}

