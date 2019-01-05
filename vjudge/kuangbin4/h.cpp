// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

// double tick() {
//     static clock_t old;
//     clock_t now = clock();
//     double diff = 1.0 * (now - old);
//     diff /= CLOCKS_PER_SEC;
//     old = now;
//     return diff;
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

const int maxn = 150;
int n, m;
int graph[maxn][maxn];

// Use floyd algorithm to check the state of winning or losing
// for each cow.
void floyd() {

    // Use the kth cow as a intermediate cow to compare.
    fori (k, 1, n + 1) fori (i, 1, n + 1) fori (j, 1, n  + 1) {
        // If the wining state is not alreay know yet.
        if (graph[i][j] == 0)  {
            // If i beats k and k bests j, the i beats j
            if (graph[i][k] && graph[i][k] == graph[k][j]) {
                graph[i][j] = graph[i][k];
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    fori (i, 0, m) {
        int u, v;
        cin >> u >> v;
        // cow u can beat cow v
        graph[u][v] = 1;
        // cow v can beat cow u
        graph[v][u] = -1;
    }

    floyd();

    // For each cow, check if the number of cows it wins
    // plus the number of cows it loses equals n - 1.
    int ret = 0;
    fori (i, 1, n + 1) {
        int win = 0, lose = 0;
        fori (j, 1, n + 1) {
            if (graph[i][j] == 1) {
                ++win;
            } else if (graph[i][j] == -1) {
                ++lose;
            }
        }
        if (win + lose == n - 1) {
            ++ret;
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
