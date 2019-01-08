// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

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

// TODO(landcold7): somehow still can't pass the judge.

typedef struct Stop {
    int x, y, id, num;
} Stop;

const int maxn = 300;
const int speed_walk = 10;
const int speed_subway = 40;

Stop stops[maxn];
double gg[maxn][maxn];
double dist[maxn];
int stop_cnt, line_cnt;

double calc(Stop a, Stop b) {
    double r = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    // If stop a and stop b are in the same subway line.
    if (a.id == b.id) {
        // These two stops are not adjcent.
        if (a.num + 1 != b.num && a.num - 1 != b.num) {
            return -1;
        } else {
            return sqrt(r) * 1.0 / (speed_subway * 1000) * 60;
        }
    } else {
// If two stops are not in the same subway line, two choices here:
//      1) directly go to another stop by walking
//      2) take a subway to get to another stop???
        return sqrt(r) * 1.0 / (speed_walk * 1000) * 60;
    }
}


void dijkstra() {
    fori (i, 0, stop_cnt + 1) {
        dist[i] = 10000000;
    }

    typedef pair<double, int> pdi;

    priority_queue<pdi, vector<pdi>, greater<pdi> > dq;
    dq.push({0, 0});
    dist[0] = 0;

    while (sz(dq)) {
        pdi p = dq.top(); dq.pop();
        int d = p.first, u = p.second;
        if (d <= dist[u]) {
            // trace(u, dist[u]);
            fori (v, 0, stop_cnt + 1) {
                double w = gg[u][v];
                if (w > 0 && v != u && dist[v] > dist[u] + w) {
                    // trace(u, v, w, dist[v], dist[u]);
                    dist[v] = dist[u] + w;
                    dq.push({dist[v], v});
                }
            }
        }
    }

    // par(dist, stop_cnt + 1, 1);
    output(int(dist[stop_cnt] + 0.5));
}

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> ws;

    string inp;
    line_cnt = stop_cnt = 1;

    int x, y;
    while (cin >> x >> y) {
        if (x == -1 && y == -1) {
            ++line_cnt;
        } else {
            stops[stop_cnt] = {x, y, line_cnt, stop_cnt};
            ++stop_cnt;
        }
    }

    // Put home and school into stops.
    stops[0] = {x1, y1, 0, 0};
    stops[stop_cnt] = {x2, y2, line_cnt, stop_cnt};

    // trace(line_cnt, stop_cnt);
    // fori (i, 0, stop_cnt + 1) {
    //     trace(i, stops[i].x, stops[i].y, stops[i].id, stops[i].num);
    // }

    // Build cost graph.
    fori (i, 0, stop_cnt + 1) {
        fori (j, i + 1, stop_cnt + 1) {
            gg[j][i] = gg[i][j] = calc(stops[i], stops[j]);
        }
    }

    // fori (i, 0, stop_cnt + 1) {
    //     par(gg[i], stop_cnt + 1, 1);
    // }

    dijkstra();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
