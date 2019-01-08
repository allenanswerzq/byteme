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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

struct fraction {
    long long numer, denom;

    void reduce() {
        long long g = gcd(numer, denom);
        numer /= g;
        denom /= g;
    }

    bool operator==(const fraction &other) const {
        return numer == other.numer && denom == other.denom;
    }
};

long long power10(int n) {
    return n == 0 ? 1 : 10 * power10(n - 1);
}

fraction to_fraction(string S) {
    string tt = S;
    size_t period = S.find('.');

    if (period == string::npos) {
        return {stoll(S), 1};
    }

    long long integer = stoll(S.substr(0, period));
    // cerr << "integer = " << integer << endl;
    S = S.substr(period + 1);

    if (S.empty()) {
        return {integer, 1};
    }

    size_t paren = S.find('(');

    if (paren == string::npos) {
        int n = S.size();
        long long p = power10(n);
        return {integer * p + stoll(S), p};
    }

    long long p = power10(paren);
    long long nonrepeating = paren == 0 ? 0 : stoll(S.substr(0, paren));

    string remaining = S.substr(paren + 1, S.size() - 1 - (paren + 1));
    long long rp = power10(remaining.size()) - 1;
    long long repeating = stoll(remaining);

    trace(tt, integer, paren, p, nonrepeating, remaining, rp, repeating);
    return {integer * p * rp + nonrepeating * rp + repeating, p * rp};
}

class Solution {
public:
    bool isRationalEqual(string S, string T) {
        fraction A = to_fraction(S);
        fraction B = to_fraction(T);
        cout << A.numer << ' ' << A.denom << endl;
        cout << B.numer << ' ' << B.denom << endl;
        A.reduce();
        B.reduce();
        return A == B;
    }
};

void test(string a, string b) {
    Solution go;
    bool ok = go.isRationalEqual(a, b);
    output(ok);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    test("0.(52)", "0.5(25)");
    test("0.1666(6)", "0.166(66)");
    test("0.9(9)", "1.");
    return 0;
}
