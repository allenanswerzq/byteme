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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<deque<int>> pos(3);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - '0'].pb(i);
    }

    for (int i = 0; i < 3; ++i) {
        if (sz(pos[i]) > n / 3) {
            vector<int> ord;
            if (i == 0) {
                // If it is 0, replace furthest first.
                ord = {2, 1};
            } else if (i == 1) {
                ord = {0, 2};
            } else {
                ord = {0, 1};
            }
            for (int j : ord) {
                while (sz(pos[i]) > n / 3 && sz(pos[j]) < n / 3) {
                    if (i > j) {
                        int x = pos[i].front();
                        s[x] = char(j + '0');
                        pos[i].pop_front();
                        pos[j].pb(x);
                    } else {
                        int x = pos[i].back();
                        s[x] = char(j + '0');
                        pos[i].pop_back();
                        pos[j].pb(x);
                    }
                }
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
