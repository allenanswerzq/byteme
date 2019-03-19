//============================================================================
// Name        : m
// Date        : Tue Mar 19 20:16:59 CST 2019
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

void amax(int &a, int b) {
    a = max(a, b);
}

string a, b;
void solve() {
    int A = sz(a), B = sz(b);
    vvi dp(A + 1, vi(B + 1));
    for (int i = 1; i <= A; ++i) {
        for (int j = 1; j <= B; ++j) {
            if (a[i - 1] == b[j - 1]) {
                amax(dp[i][j], dp[i-1][j-1] + 1);
            }
            amax(dp[i][j], dp[i-1][j]);
            amax(dp[i][j], dp[i][j-1]);
        }
    }
    // trace(dp);
    output(dp[A][B]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> a >> b) {
        solve();
    }
    return 0;
}

