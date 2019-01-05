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

unordered_map<int, int> need_open;
unordered_map<int, int> need_close;

pii get(string& ss) {
    int need_open = 0;
    deque<int> stk;
    fori (i, 0, sz(ss)) {
        char c = ss[i];
        if (c == ')') {
            if (sz(stk) == 0) {
                ++need_open;
            } else {
                stk.pop_back();
            }
        } else {
            stk.pb(i);
        }
    }

    int need_close = sz(stk);
    return {need_open, need_close};
}

void solve() {
    int n; cin >> n;
    int zeros = 0;
    fori (i, 0, n) {
        string s; cin >> s;
        pii var = get(s);
        int left = var.first, right = var.second;
        if (left == 0 && right == 0) {
            ++zeros;
        } else if (left == 0 && right != 0) {
            ++need_close[right];
        } else if (left != 0 && right == 0) {
            ++need_open[left];
        }
    }

    int ret = zeros / 2;
    fora (right, need_close) {
        int need = right.first, cnt = right.second;
        if (need_open.count(need) && need_open[need]) {
            int tmp = min(cnt, need_open[need]);
            need_open[need] -= tmp;
            ret += tmp;
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
