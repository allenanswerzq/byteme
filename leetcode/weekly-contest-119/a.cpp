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

int dist(vi& a, vi& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& aa, int k) {
        vi zero = {0, 0};
        map<int, vvi> mp;
        fori (i, 0, sz(aa)) {
            int d = dist(aa[i], zero);
            mp[d].pb(aa[i]);
        }

        int c = 0;
        vvi ret;
        fora (m, mp) {
            fora (v, m.second) {
                if (c < k) {
                    ret.pb(v);
                    ++c;
                }
            }
        }
        return ret;
    }
};

void test(vvi aa, int k) {
    Solution go;
    vvi ret = go.kClosest(aa, k);
    fora (r, ret) {
        pvi(r, 0);
    }
}

int main() {
    test({{1, 3}, {-2, 2}}, 1);
    test({{3,3}, {5,-1}, {-2,4}}, 2);
    return 0;
}
