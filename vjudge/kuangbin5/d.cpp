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
    // sum[i] denotes the sum following the path from node i up to the root.
    // As long as two nodes are linked to a same root, we can get the their
    // difference by sum[v] - sum[u]
    vi e, sum;
    int count;
    UF(int n) : e(n + 1, -1), sum(n + 1, 0), count(0) {}

    int find(int x) {
        if (e[x] < 0) return x;
        // Path compression.
        int root = find(e[x]);
        sum[x] += sum[e[x]];
        e[x] = root;
        return root;
    }

    void join(int u, int v, int w) {
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2) {
            // Add link by rank gives WA.
            // if (e[t1] > e[t2]) swap(t1, t2);
            // e[t1] += e[t2];
            e[t2] = t1;
            // Hard to understand.
            sum[t2] = sum[u] - sum[v] + w;
        } else {
            if (sum[v] - sum[u] != w) {
                ++count;
            }
        }
    }

    int answer() {
        return count;
    }
};

int n, m;
void solve() {
    UF uf(n);
    fori (i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        uf.join(u - 1, v, w);
    }
    output(uf.answer());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        solve();
    }
    return 0;
}

