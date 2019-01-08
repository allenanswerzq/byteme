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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xs = {1}, ys = {1};

        if (x > 1)
            for (int p = x; p <= bound; p *= x)
                xs.push_back(p);

        if (y > 1)
            for (int p = y; p <= bound; p *= y)
                ys.push_back(p);

        set<int> s;

        for (int xx : xs)
            for (int yy : ys)
                if (xx + yy <= bound)
                    s.insert(xx + yy);

        return vector<int>(s.begin(), s.end());
    }
};

// Messy solution by me.

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ret;

        if (x != 1 && y != 1) {
            fori (i, 0, 100000) {
                fori (j, 0, 100000) {
                    int sum = pow(x, i) + pow(y, j);
                    // trace(i, j, sum);
                    if (0 < sum && sum <= bound) {
                        ret.insert(sum);
                    } else {
                        break;
                    }
                }
            }
        } else if (x == 1 && y == 1) {
            if (bound >= 2) {
                ret.insert(2);
            }
        } else if (x == 1 && y != 1) {
            fori (j, 0, 100000) {
                int sum = 1 + pow(y, j);
                if (0 < sum && sum <= bound) {
                    ret.insert(sum);
                }
            }
        } else {
            fori (i, 0, 100000) {
                int sum = 1 + pow(x, i);
                if (0 < sum && sum <= bound) {
                    ret.insert(sum);
                }
            }
        }

        vi ans(all(ret));
        return ans;
    }
};

void test(int x, int y, int bound) {
    Solution go;
    vi ret = go.powerfulIntegers(x, y, bound);
    pvi(ret, 1);
}

int main() {
    test(1, 1, 3);
    test(1, 1, 0);
    test(1, 1, 2);
    test(2, 3, 10);
    test(3, 5, 15);
    return 0;
}
