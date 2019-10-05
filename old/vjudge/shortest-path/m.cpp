// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//     cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//     const char* split = strchr(names + 1, ',');
//     cout.write(names, split - names) << ": " << arg << " |";
//     _f(split, args...);
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 200;
const int inf = 0x3f3f3f3f;

int gg[maxn][maxn];
int dist[maxn];
int prices[maxn], ranks[maxn];
int m, n, ret;

// Do dijkstra for each item in the range of [low ... high].
void dijkstra(int low, int high) {
    mst(dist, 0x3f);

    priority_queue<pii, vpii, greater<pii> > dq;
    dq.push({0, 1});
    dist[1] = 0;

    while (sz(dq)) {
        pii p = dq.top(); dq.pop();
        int d = p.first, u = p.second;
        if (d <= dist[u]) {
            fori (v, 1, n + 1) {
                int w = gg[u][v], nd = dist[u] + w;
                if (w && low <= ranks[v] && ranks[v] <= high && dist[v] > nd) {
                    dist[v] = nd;
                    dq.push({dist[v], v});
                }
            }
        }
    }

    // As long as there is a path from the first item to the ith one,
    // we know that, there is a item replaceable path from ith item up to
    // the first one.
    fori (i, 1, n + 1) {
        if (dist[i] != inf) {
            ret = min(ret, dist[i] + prices[i]);
        }
    }

}

void solve() {
    cin >> m >> n;
    fori (i, 1, n + 1) {
        int price, rank, alt_cnt;
        cin >> price >> rank >> alt_cnt;
        prices[i] = price;
        ranks[i] = rank;
        fori (j, 0, alt_cnt) {
            int alt_id, alt_price;
            cin >> alt_id >> alt_price;
            // Use alternative item plus alternative price to replace
            // the ith original item.
            gg[i][alt_id] = alt_price;
        }
    }

    // Since the goal here is to get the first item, so it's rank
    // must be included. use this as a center value to spread to both
    // left and right sides.
    ret = (1 << 30);
    int center_rank = ranks[1];
    fori (r, center_rank - m, center_rank + 1) {
        int low = r, high = r + m;
        dijkstra(low, high);
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
