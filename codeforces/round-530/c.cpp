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

// Messy solution by me.
void solve2() {
    string msg; int k;
    cin >> msg >> k;

    int min_len = 0;
    set<int> aa, bb;

    fori (i, 0, sz(msg)) {
        char s = msg[i];
        if (s == '?') {
            aa.insert(i - 1);
            --min_len;
        } else if (s == '*') {
            bb.insert(i - 1);
            --min_len;
        } else {
            ++min_len;
        }
    }

    if (min_len > k || (min_len < k && sz(aa) == 0 && sz(bb) == 0)) {
        output("Impossible");
        return;
    }

    // Extra needed chars.
    int extra = k - min_len;
    string ret;
    if (sz(bb)) {
        fori (i, 0, sz(msg)) {
            if (msg[i] != '?' && msg[i] != '*') {
                if (aa.count(i)) {

                } else if (bb.count(i)) {
                    while (extra) {
                        ret += msg[i];
                        --extra;
                    }
                } else {
                    ret += msg[i];
                }
            }
        }
    } else {
        if (extra > sz(aa)) {
            output("Impossible");
            return;
        }

        fori (i, 0, sz(msg)) {
            if (msg[i] != '?' && msg[i] != '*') {
                if (aa.count(i)) {
                    if (extra) {
                        ret += msg[i];
                        --extra;
                    }
                } else {
                    ret += msg[i];
                }
            }
        }
    }

    output(ret);

}

// More elegant solution.
void solve() {
    string msg; int k;
    cin >> msg >> k;

    vector<pair<char, char> > data;

    for (auto c : msg) {
        if (c == '?' || c == '*') {
            data.back().second = c;
        } else {
            data.pb({c, '-'});
        }
    }

    int min_len = 0;
    int max_len = 0;
    bool has_star = false;

    for (auto p : data) {
        if (p.second == '-') {
            min_len++;
            max_len++;
        }
        else if (p.second == '?') {
            max_len++;
        }
        else {
            has_star = true;
            max_len += 500;
        }
    }

    if (min_len > k || max_len < k) {
        output("Impossible");
        return;
    }

    int extra = k - min_len;
    // trace(extra, min_len);
    string ret;
    if (has_star) {
        for (auto p : data) {
            if (p.second == '-') {
                ret += p.first;
            } else if (p.second == '?') {

            } else {
                while (extra) {
                    ret += p.first;
                    --extra;
                }
            }
        }
    } else {
        for (auto p : data) {
            if (p.second == '-') {
                ret += p.first;
            } else if (p.second == '?') {
                if (extra) {
                    ret += p.first;
                    --extra;
                }
            }
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
