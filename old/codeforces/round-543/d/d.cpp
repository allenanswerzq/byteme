//============================================================================
// Name        : d
// Date        : Mon Mar 11 14:47:06 CST 2019
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
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vi aa(m);
    fori (i, 0, m) {
        cin >> aa[i];
    }

    vi ss(s);
    map<int, int> need;
    fori (i, 0, s) {
        cin >> ss[i];
        need[ss[i]]++;
    }

    int good = 0;
    map<int, int> have;
    auto add = [&] (int x) {
        have[x]++;
        if (have[x] == need[x]) {
            ++good;
        }
    };

    auto del = [&] (int x) {
        if (have[x] == need[x]) {
            --good;
        }
        have[x]--;
    };

    // trace(need, have);

    int r = 0;
    s = sz(need);
    fori (l, 0, m) {
        while (r < m && good < s) {
            add(aa[r++]);
        }

        // [x x x (l......) r], cut [l, r - 1] as a whole part.
        int wasted = l % k + max(0, r - l - k);
        if (m - wasted >= n * k && good == s) {
            // trace(l, r, wasted, k, good, s, have, need);
            // Remove some numbers at the beginning to make `l` as a
            // staring position for a new cut.
            vi bad;
            fori (i, 0, l % k) {
                bad.pb(i);
            }

            // Remove other numbers to make this new cut with length `k`.
            have.clear();
            vi bb;
            fori (i, l, r) {
                if (have[aa[i]] + 1 <= need[aa[i]]) {
                    have[aa[i]]++;
                } else {
                    bb.pb(i);
                }
            }
            while (sz(bb) > max(0, r - l - k)) {
                bb.pop_back();
            }

            bad.insert(bad.end(), all(bb));

            fora (x, bad) {
                x += 1;
            }

            output(sz(bad));
            par(bad, 0, sz(bad), 0);
            return;
        }

        del(aa[l]);
    }
    output(-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

