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

// #define EXTERNAL

bool prime(ll inp) {
  if (((!(inp & 1)) && inp != 2 ) || 
       (inp < 2) || 
       (inp % 3 == 0 && inp != 3))
    return false;

  for (ll k = 1; 36 * k * k - 12 * k < inp; ++k) {
    if ((inp % (6 * k + 1) == 0) ||
        (inp % (6 * k - 1) == 0))
      return false;   
  }
  return true;
}

int main(int argc, char** argv) {
#ifdef EXTERNAL
  // freopen("1033b-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    ll a, b; cin >> a >> b; 
    // trace(a + b, a - b);
    if (a - b == 1 && prime(a + b)) outret("YES");
    else outret("NO");
  }

#ifdef EXTERNAL
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << '\n';
#endif

  return 0;
}

