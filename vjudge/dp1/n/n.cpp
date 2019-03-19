//============================================================================
// Name        : n
// Date        : Tue Mar 19 20:31:32 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Node {
    int start;
    int end;
    int height;
    bool operator<(const Node &b) const {
        return height < b.height;
    }
    // friend dbstream& operator<<(dbstream& os, Node &n) {
    //     os << "Node(" << n.start << " " << n.end << " "
    //        << n.height << ")\n";
    //     return os;
    // }
};

const int inf = (int)1e9 + 7;
void amin(int &a, int b) {
    a = min(a, b);
}

void solve() {
    int n, x, y, mx;
    cin >> n >> x >> y >> mx;

    vector<Node> a(n);
    for (auto &t : a) {
        cin >> t.start >> t.end >> t.height;
    }
    a.pb({x, x, y});

    // sort(all(a), [](Node &a, Node &b) {
    //     return a.height < b.height;
    // });
    sort(all(a));

    vvi dp(n + 1, vi(2, inf));
    for (int i = 0; i <= n; ++i) {
        int jump_left = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (a[j].start <= a[i].start && a[i].start <= a[j].end) {
                jump_left = j;
                break;
            }
        }

        int jump_right = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (a[j].start <= a[i].end && a[i].end <= a[j].end) {
                jump_right = j;
                break;
            }
        }

        // trace(i, jump_left, jump_right);
        if (jump_left == -1 && a[i].height <= mx) {
            dp[i][0] = a[i].height;
        }

        if (jump_right == -1 && a[i].height <= mx) {
            dp[i][1] = a[i].height;
        }

        if (jump_left != -1 && a[i].height - a[jump_left].height <= mx) {
            amin(dp[i][0], dp[jump_left][0] + a[i].start - a[jump_left].start);
            amin(dp[i][0], dp[jump_left][1] + a[jump_left].end - a[i].start);
            dp[i][0] += a[i].height - a[jump_left].height;
        }

        if (jump_right != -1 && a[i].height - a[jump_right].height <= mx) {
            amin(dp[i][1], dp[jump_right][0] + a[i].end - a[jump_right].start);
            amin(dp[i][1], dp[jump_right][1] + a[jump_right].end - a[i].end);
            dp[i][1] += a[i].height - a[jump_right].height;
        }
    }
    // trace(a, dp);
    assert(dp[n][0] == dp[n][1]);
    output(dp[n][1]);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

