// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
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

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return -e[find(x)];
    }

    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
    }
};

typedef struct Point {
    int x, y;
} Point;

const int maxn = 1008;

Point points[maxn];
bool repaired[maxn];
int n, d;

double dist(Point a, Point b) {
    double r = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(r);
}

void solve() {
    cin >> n >> d;
    mst(points, 0);
    fori (i, 1, n + 1) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    UF uf(n);
    char op;
    mst(repaired, 0);
    while (cin >> op) {
        if (op == 'O') {
            int x; cin >> x;
            repaired[x] = 1;
            fori (i, 1, n + 1) {
                if (i != x && repaired[i] && dist(points[i], points[x]) <= d) {
                    uf.join(i, x);
                }
            }
        } else if (op == 'S') {
            int a, b; cin >> a >> b;
            if (uf.same_set(a, b)) {
                output("SUCCESS");
            } else {
                output("FAIL");
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
