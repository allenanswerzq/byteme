//============================================================================
// Name        : c
// Date        : Thu Jan 24 22:27:14 CST 2019
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

void solve() {
    int n; string ss;
    cin >> n >> ss;

    vs patts = {"BGR", "BRG", "GBR", "GRB", "RBG", "RGB"};

    int ret_cost = numeric_limits<int>::max();
    string ret_pat;
    fora (pat, patts) {
        int cost = 0;
        for (int i = 0; i < n; i += 3) {
            string sub = ss.substr(i, 3);
            fori (j, 0, sz(sub)) {
                if (sub[j] != pat[j]) ++cost;
            }
        }
        if (cost < ret_cost) {
            ret_cost = cost;
            ret_pat = pat;
        }
    }

    output(ret_cost);
    for (int i = 1; i <= (n + 3) / 3; ++i) {
        if (i < (n + 3) / 3) cout << ret_pat;
        else cout << ret_pat.substr(0, n % 3);
    }
    cout << "\n";
}

void solve2() {
    int n; string ss;
    cin >> n >> ss;

    vi idx(3); iota(all(idx), 0);

    string colors = "RGB";
    string ret_str;
    int ret_cost = numeric_limits<int>::max();
    do {
        string str;
        int cost = 0;
        fori (i, 0, n) {
            str += colors[idx[i % 3]];
            cost += str[i] != ss[i];
        }
        if (cost < ret_cost) {
            ret_cost = cost;
            ret_str = str;
        }
    } while (next_permutation(all(idx)));

    output(ret_cost);
    output(ret_str);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve2();
    return 0;
}

