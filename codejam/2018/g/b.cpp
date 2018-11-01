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
  cout << name << ": " << arg << '\n';
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

const int maxn = 5 * 1e5;
ll xx[maxn], yy[maxn], zz[maxn];
ll aa[maxn], bb[maxn];
ll qq[maxn], rr[maxn];
ll N, Q; 

void gen() {
  cin >> N >> Q;
  ll X1, X2, A1, B1, C1, M1;
  ll Y1, Y2, A2, B2, C2, M2;
  ll Z1, Z2, A3, B3, C3, M3; 

  cin >> X1 >> X2 >> A1 >> B1 >> C1 >> M1;
  cin >> Y1 >> Y2 >> A2 >> B2 >> C2 >> M2;
  cin >> Z1 >> Z2 >> A3 >> B3 >> C3 >> M3; 

  xx[1] = X1, xx[2] = X2; 
  yy[1] = Y1, yy[2] = Y2;
  zz[1] = Z1, zz[2] = Z2;

  fori (i, 3, N + 1) 
    xx[i] = (A1 * xx[i-1] + B1 * xx[i-2] + C1) % M1; 

  fori (i, 3, N + 1)
    yy[i] = (A2 * yy[i-1] + B2 * yy[i-2] + C2) % M2;

  fori (i, 3, Q + 1)
    zz[i] = (A3 * zz[i-1] + B3 * zz[i-2] + C3) % M3;

  fori (i, 1, N + 1) {
    aa[i] = min(xx[i], yy[i]) + 1;
    bb[i] = max(xx[i], yy[i]) + 1;
  }

  fori (i, 1, Q + 1) {
    qq[i] = zz[i] + 1;
  } 

  trace(N, Q);
  par(aa, N + 1, 1);
  par(bb, N + 1, 1);
  par(qq, Q + 1, 1);
}

// Returns the number of students scoring more than or equal x. 
ll number(int x) {
  ll r = 0;
  fori (i, 1, N + 1) {
    if (x <= bb[i])
      r += bb[i] - max(x * 1ll, aa[i]) + 1;
  }
  return r;
} 

ll small() {
  gen();
  ll ret = 0;
  fori (q, 1, Q + 1) {
    int lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (number(mid) >= qq[q]) {
        lo = mid + 1;
        ans = mid;
      } else hi = mid - 1;
    } 
    ret += q * ans * 1ll;
  }
  return ret;
}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    ll r = small();
    codejam(i, r);
  }
  return 0;
}

