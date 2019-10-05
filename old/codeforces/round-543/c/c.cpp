//============================================================================
// Name        : c
// Date        : Sun Mar 10 10:42:38 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
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
    int n, k;
    cin >> n >> k;
    vi aa(n + 1);
    fori (i, 1, n + 1) {
        cin >> aa[i];
    }

    vi cpu(k), jobs(n * 150), start(n + 1);
    int m = 0, tested_cnt = 0;
    fori (t, 0, n * 150) {
        fori (j, 0, k) {
            if (cpu[j] == t) {
            // This cpu has no task to do right now,
            // Bring one from queue into it
                if (m < n) {
                    cpu[j] = t + aa[++m];
                    start[m] = t;
                }
                if (t) {
                // How many solutions are already been
                // tested before this moment?
                    ++tested_cnt;
                }
            }
        }
        jobs[t] = tested_cnt;
    }

    // trace(start, jobs);

    int ret = 0;
    fori (i, 1, n + 1) {
        int L = start[i], R = start[i] + aa[i];
        // trace(L, R);
        fori (j, L, R) {
            int x = j - L + 1;
            int d = (100.0 * jobs[j] / n + 0.5);
            if (x == d) {
                ++ret;
                break;
            }
        }
    }
    output(ret);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

