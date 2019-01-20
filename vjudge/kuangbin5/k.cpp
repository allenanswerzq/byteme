//============================================================================
// Name        : k
// Date        : Sat Jan 19 17:46:01 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
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
    vi e, val;

    UF(int n) : e(n + 1, -1), val(n + 1, 0) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int root = find(e[x]);
        val[x] = (val[x] + val[e[x]]) % 3;
        e[x] = root;
        return root;
    }

    bool same_set(int u, int v) {
        return find(u) == find(v);
    }

    void join(int u, int v, int w) {
        int t1 = find(u), t2 = find(v);
        if (t1 != t2) {
            e[t2] = t1;
            val[t2] = (val[u] - val[v] + w + 3) % 3;
        }
    }

    int get(int u) {
        return val[u];
    }
};

const int maxm = 2010;
struct Game {
    int u, v, w;
} game[maxm];

int n, m;
void solve() {
    fori (i, 0, m) {
        int u, v, w; char op;
        cin >> u >> op >> v;
        // trace(u, op, v);
        if (op == '=') w = 0;
        else if (op == '<') w = 1;
        else w = 2;
        game[i] = {u, v, w};
    }

    int judge = -1, count = 0, tot = 0;
    // Chose index i as judge.
    fori (i, 0, n) {
        UF uf(n);
        int brk = -1;
        fori (j, 0, m) {
            int u = game[j].u, v = game[j].v, w = game[j].w;
            if (u == i || v == i) continue;

            if (uf.same_set(u, v)) {
                // If this operation doesn't make any sense.
                if (uf.get(v) != (uf.get(u) + w) % 3) {
                    brk = j + 1;
                    break;
                }
            } else {
                uf.join(u, v, w);
            }
        }

        if (brk == -1) {
        // If chose index i as judge doesn't cause contradiction.
            ++tot;
            judge = i;
        } else {
            count = max(count, brk);
        }
    }

    // trace(tot, judge, count);

    if (tot == 0) {
        output("Impossible");
    } else if (tot >= 2) {
        output("Can not determine");
    } else if (tot == 1) {
        cout << "Player " << judge << " can be determined to be the judge after"
             << " " << count << " lines\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        solve();
    }
    return 0;
}
