//============================================================================
// Name        : n
// Date        : Mon Jan 21 17:52:38 CST 2019
// Author      : landcold7
// Copyright   : Your copyright notice
// Description : None
//============================================================================
#include <bits/stdc++.h>
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

const int maxn = (int) 1e5 + 7;
struct UF {
    vi e;
    UF(int n) : e(n + 1, -1) {}

    int find(int x) {
        if (e[x] < 0) return x;
        e[x] = find(e[x]);
        return e[x];
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
};

void solve() {
    int a, b;
    while (cin >> a >> b) {
        if (a == -1 && b == -1) break;
        if (a == 0 && b == 0) {
            output("Yes");
            continue;
        }

        bool ok = 1;
        set<int> st;
        UF uf(maxn);
        uf.join(a, b);
        st.insert(a);
        st.insert(b);
        while (cin >> a >> b) {
            if (a == 0 && b == 0) break;
            if (uf.same_set(a, b)) {
                ok = 0;
            } else {
                st.insert(a);
                st.insert(b);
                uf.join(a, b);
            }
        }

        if (ok) {
            int k = 0;
            fora (t, st) {
                if (uf.e[t] < 0) ++k;
            }
            if (k > 1) ok = 0;
        }
        output(ok ? "Yes" : "No");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

