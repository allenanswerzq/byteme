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
    int largestPerimeter(vector<int>& aa) {
        sort(all(aa), greater<int>());
        int n = sz(aa), ret = 0;
        fori (i, 0, n - 2) {
            if (aa[i] < aa[i + 1] + aa[i + 2]) {
                ret = max(ret, aa[i] + aa[i + 1] + aa[i + 2]);
            }
        }
        return ret;
    }
};

void test(vi aa) {
    Solution go;
    int ret = go.largestPerimeter(aa);
    output(ret);
}

int main() {
    test({2, 1, 2});
    test({1, 2, 1});
    test({3, 2, 3, 4});
    test({3, 6, 2, 3});
    return 0;
}
