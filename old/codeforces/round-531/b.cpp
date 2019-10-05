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

const int maxn = 5002;
int cnt[maxn];
vi idx[maxn];

void solve() {
    int n, k; cin >> n >> k;
    fori (i, 0, n) {
        int x; cin >> x;
        ++cnt[x];
        idx[x].pb(i);
    }

    vi ret(n, 0);
    int c = 1;
    bool ok = 0;
    fori (i, 0, maxn) {
        if (cnt[i]) {
            if (cnt[i] > k) {
                output("NO");
                return;
            } else {
                fori (j, 0, cnt[i]) {
                    ret[idx[i][j]] = c++;
                    if (c > k) {
                        ok = 1;
                        c = 1;
                    }
                }
            }
        }
    }

    if (!ok) {
        output("NO");
    } else {
        output("YES");
        pvi(ret, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
