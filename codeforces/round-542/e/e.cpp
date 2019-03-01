//============================================================================
// Name        : e
// Date        : Fri Mar  1 17:03:47 CST 2019
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

const int inf = (int) 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> stations(n);
    fori (i, 0, m) {
        int a, b;
        cin >> a >> b;
        stations[a - 1].pb(b - 1);
    }


    vi dist(n);
    fori (i, 0, n) {
        int mi = inf;
        fora (dst, stations[i]) {
            int tmp = (dst - i + n) % n;
            mi = min(mi, tmp);
        }
        dist[i] = mi;
    }

    // trace(stations);

    fori (start, 0, n) {
        int mx_start = 0;
        for (int cur_station = start; ;) {
            int candy_num = sz(stations[cur_station]);
            if (candy_num) {
                int time = (cur_station - start + n) % n;
                time += dist[cur_station] + (candy_num - 1) * n;
                mx_start = max(mx_start, time);
            }
            cur_station = (cur_station + 1) % n;
            if (cur_station == start) break;
        }
        cout << mx_start << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

