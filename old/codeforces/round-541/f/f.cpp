//============================================================================
// Name        : f
// Date        : Wed Feb 27 22:09:45 CST 2019
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
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"

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

struct UF {
    vi e;
    vvi cage;
    UF(int n) : e(n, -1), cage(n + 1) {
        fori (i, 1, n + 1) {
            cage[i].pb(i);
        }
    }

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
        if (cage[b].size() > cage[a].size()) {
            swap(b, a);
        }

        fora (animal, cage[b]) {
            cage[a].pb(animal);
        }

        e[b] = a;
    }
};

void solve() {
    int n; cin >> n;
    UF uf(n + 1);
    fori (i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        uf.join(x, y);
    }

    int root = uf.find(1);
    fora (x, uf.cage[root]) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

