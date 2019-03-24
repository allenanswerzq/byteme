//============================================================================
// Name        : c
// Date        : Sat Mar 23 20:32:41 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Word {
    int n;
    char first, last;
    array<int, 26> cnt = {0};
    Word() {}
    Word(string& s) : n(sz(s)), first(s[0]), last(s[n - 1]) {
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
    }
    bool operator==(const Word& w) const {
        return first == w.first && last == w.last && cnt == w.cnt;
    }
    // friend dbstream& operator<<(dbstream& os, Word& w) {
    //     os << "Word(" << w.first << " " << w.last << " " << w.cnt << ")\n";
    //     return os;
    // }
};

struct WordHash {
    size_t operator()(const Word& w) const {
        size_t ha = w.first + 31 * w.last;
        for (auto c : w.cnt) {
            ha = 31 * ha + c;
        }
        return ha;
    }
};

string str;
vector<string> dict;

int large() {
    unordered_map<Word, int, WordHash> mp;
    unordered_set<int> lengths;
    for (auto d : dict) {
        mp[Word(d)]++;
        lengths.insert(sz(d));
    }
    // trace(str);
    int ret = 0;
    for (auto w : lengths) {
        if (w > sz(str)) {
            continue;
        }
        Word sub;
        for (int i = 0; i < sz(str); ++i) {
            if (i < w) {
                sub.cnt[str[i] - 'a']++;
            } else {
                sub.cnt[str[i - w] - 'a']--;
                sub.cnt[str[i] - 'a']++;
            }
            if (i < w - 1) {
                continue;
            }
            sub.first = str[i - w + 1];
            sub.last = str[i];
            string sb = str.substr(i - w + 1, w);
            // trace(sb, sub, mp.count(sub));
            auto it = mp.find(sub);
            if (it != mp.end()) {
                ret += it->y;
                mp.erase(it);
            }
        }
    }
    return ret;
}

void solve(int cs) {
    int L; cin >> L;
    dict = vs(L);
    for (auto &t : dict) {
        cin >> t;
    }

    char S1, S2; int N, A, B, C, D;
    cin >> S1 >> S2 >> N >> A >> B >> C >> D;
    str = string(N, 'a');
    str[0] = S1, str[1] = S2;
    ll x1 = S1, x2 = S2;
    for (int i = 3; i <= N; ++i) {
        ll xi = ( A * x2 + B * x1 + C ) % D;
        str[i - 1] = 'a' + ( xi % 26 );
        x1 = x2;
        x2 = xi;
    }
    jam(cs, large());
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

