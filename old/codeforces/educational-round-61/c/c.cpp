//============================================================================
// Name        : c
// Date        : Tue Mar 12 16:28:59 CST 2019
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

// TODO(landcold7): solve this problem using dp..

void solve() {
    int n, q;
    cin >> n >> q;

    vpii aa(q);
    vi cnt(n);
    fora (a, aa) {
        cin >> a.first >> a.second;
        --a.first, --a.second;
        fori (i, a.first, a.second + 1) {
            ++cnt[i];
        }
    }

    int ret = 0;
    fori (i, 0, q) {
        vi bb = cnt, ones(n);
        fori (j, aa[i].first, aa[i].second + 1) {
            --bb[j];
        }

        int remain = 0;
        fori (j, 0, n) {
            if (bb[j]) {
                ++remain;
            }
            if (bb[j] == 1) {
                ones[j] = 1;
            }
        }

        vi pre(n + 1);
        fori (j, 1, n + 1) {
            pre[j] = pre[j - 1] + ones[j - 1];
        }

        auto get_sum = [&] (int L, int R) {
            return pre[R] - (L ? pre[L - 1] : 0);
        };

        fori (j, i + 1, q) {
            int lost = get_sum(aa[j].first + 1, aa[j].second + 1);
            ret = max(ret, remain - lost);
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

