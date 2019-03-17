//============================================================================
// Name        : a
// Date        : Wed Mar 13 21:43:56 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define first x
#define second y
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

void solve() {
    int h1, m1, h2, m2; char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    // trace(h1, m1, h2, m2);
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    int t3 = (t1 + t2) / 2;

    int h3 = t3 / 60, m3 = t3 % 60;
    printf("%02d:%02d\n", h3, m3);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

