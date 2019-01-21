//============================================================================
// Name        : o
// Date        : Mon Jan 21 19:21:32 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

#define pb push_back
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; cout << '\n'
#define par(x, s, n, v) if(v) pvar(x); fori(a, s, n) prt(x, a, n) cout << '\n'

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
    UF(int n) : e(n + 1, -1) {}

    int find(int x) {
        if (e[x] < 0) return x;
        int root = find(e[x]);
        return root;
    }

    void join(int a, int b) {
        int t1 = find(a), t2 = find(b);
        if (t1 != t2) {
            e[t2] = t1;
        }
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    void clear() {
        e.resize(sz(e), -1);
    }
};

const int maxn = (int) 1e5 + 7;
int in_deg[maxn];

void solve() {
    int u, v, k_case = 0, ok = 1, t0 = 0;
    set<int> st;
    UF uf(maxn);
    mst(in_deg, 0);
    while (cin >> u >> v) {
        if (u == -1 && v == -1) break;
        if (u == 0 && v == 0) {
            ++k_case;
            cout << "Case " << k_case << " ";
            vi tt(all(st));
            fori (i, 0, sz(tt)) {
                int t = tt[i];
                if (!uf.same_set(t, *st.begin())) {
                    ok = 0;
                    break;
                }
                if (in_deg[t] == 0) ++t0;
                else if (in_deg[t] > 1) {
                    ok = 0;
                    break;
                }
            }

            if (t0 != 1) ok = 0;
            if (sz(st) == 0) ok = 1;

            output(ok ? "is a tree." : "is not a tree.");

            st.clear();
            uf.clear();
            mst(in_deg, 0);
            t0 = 0;
            ok = 1;

        } else {
            st.insert(u);
            st.insert(v);
            uf.join(u, v);
            ++in_deg[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

