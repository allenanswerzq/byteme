#include <bits/stdc++.h>
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

double tick() {
    static clock_t old;
    clock_t now = clock();
    double diff = 1.0 * (now - old);
    diff /= CLOCKS_PER_SEC;
    old = now;
    return diff;
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

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> pancake;
        int n = A.size();

        for (int big = n; big > 0; big--) {
            int index = find(A.begin(), A.end(), big) - A.begin();
            pancake.push_back(index + 1);
            reverse(A.begin(), A.begin() + index + 1);
            pancake.push_back(big);
            reverse(A.begin(), A.begin() + big);
        }

        return pancake;
    }
};

// Messy solution by mine.
class Solution {
public:
    void dfs(vi &aa, vi &path, int last) {
        bool ok = 1;
        fori (i, 0, sz(aa)) {
            if (aa[i] != i + 1) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            return;
        }

        int idx = 0;
        fori (i, 0, sz(aa)) {
            if (aa[i] == last) {
                idx = i;
                break;
            }
        }

        if (idx == last - 1) {
            dfs(aa, path, last - 1);
        } else {
            path.pb(idx + 1);
            reverse(aa.begin(), aa.begin() + idx + 1);
            path.pb(last);
            reverse(aa.begin(), aa.begin() + last);
            dfs(aa, path, last - 1);
        }

    }

    vector<int> pancakeSort(vector<int>& aa) {
        vi path;
        dfs(aa, path, sz(aa));
        return path;
    }

};

void test(vi aa) {
    Solution go;
    vi ret = go.pancakeSort(aa);
    pvi(ret, 1);
}

int main() {
    test({3, 2, 4, 1});
    test({1, 2, 3});
    return 0;
}
