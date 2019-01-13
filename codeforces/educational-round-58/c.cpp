# include <bits/stdc++.h>
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

const ll step = 1e6;

void solve(int tt) {
    int n; cin >> n;
    vpii aa;
    unordered_map<ll, vi> mp;
    fori (i, 0, n) {
        int a, b; cin >> a >> b;
        aa.pb({a, b});
        mp[a * step + b].pb(i);
    }
    sort(all(aa));

    int split = -1, mx = aa[0].second;
    fori (i, 1, sz(aa)) {
        if (aa[i].first > mx) {
            split = i;
            break;
        }
        mx = max(mx, aa[i].second);
    }

    if (split == -1) {
        output(-1);
    } else {
        vi ret(n, 0);
        fori (i, 0, n) {
            ll p = aa[i].first * step + aa[i].second;
            vi indices = mp[p];
            fori (j, 0, sz(indices)) {
                if (i < split) {
                    ret[indices[j]] = 1;
                } else {
                    ret[indices[j]] = 2;
                }
            }
            mp[p].clear();
        }
        pvi(ret, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve(i);
    }
    return 0;
}
