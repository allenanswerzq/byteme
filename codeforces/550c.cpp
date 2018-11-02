#include<bits/stdc++.h>
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
#define outret(v) cout << (v) << '\n'
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// Ref: http://www.aaamath.com/div66_x8.htm 
// Numbers are divisible by 8 if the number formed by the last three individual 
// digits is evenly divisible by 8. For example, the last three digits of the 
// number 3624 is 624, which is evenly divisible by 8 so 3624 is evenly 
// divisible by 8.

// #define EXTERNAL

int main(int argc, char** argv) {
#ifdef EXTERNAL
  // freopen("550c-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  string ss; cin >> ss;
  for (int i = 0; i <= 1000; i += 8) {
    string tt = to_string(i);
    int j = 0;
    fori (i, 0, sz(ss)) {
      if (ss[i] == tt[j]) ++j;
      if (j == sz(tt)) {
        outret("YES");
        outret(tt);
        return 0;
      }
    }
  }
  outret("NO");

#ifdef EXTERNAL
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << '\n';
#endif

  return 0;
}

