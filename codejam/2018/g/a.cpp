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
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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

ll comb(int n, int k){
  if (k > n) return 0;
  if (k == 0) return 1;
  if (k * 2 > n) k = n - k;

  ll ret = n;
  for (int i = 2; i <= k; ++i) {
    ret *= (n - i + 1);
    ret /= i;
  }
  return ret;
}

const int maxn = 8000;
ll aa[maxn];
ll solve() {
  int n; cin >> n;
  int c = 0;
  fori (i, 0, n) {
    cin >> aa[i];
    if (aa[i] == 0) ++c;
  }

  sort(aa, aa + n);
  // par(aa, n, 1);

  // tick();
  ll ret = 0;
  unordered_map<ll, ll> mp;
  ford (y, n - 1, -1) {
    ford (x, y - 1, -1) {
      ll z = aa[x] * aa[y];
      if (z && mp.count(z))
        ret += mp[z];
    }
    mp[aa[y]]++;
  }
  // trace(tick());
  ret += comb(c, 3) + comb(c, 2) * (n - c) * 1ll;
  return ret;
}

ll solve2() {
  int n; cin >> n;
  fori (i, 0, n) cin >> aa[i];

  // sort(aa, aa + n);
  ll r = 0;
  fori (i, 0, n) {
    fori (j, i + 1, n) {
      fori (k, j + 1, n) {
        if (aa[i] * aa[j] == aa[k] ||
            aa[i] * aa[k] == aa[j] ||
            aa[j] * aa[k] == aa[i]) {
          ++r;
          // trace(i + 1, j + 1, k + 1);
        }
      }
    }
  }
  return r;
}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    ll r = solve();
    codejam(i, r);
  }
  return 0;
}
