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

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b) {
  if (a.end != b.end)
    return a.end < b.end;
  return a.start < b.start;
}

const int maxn = 5 * 1e5;
ll xx[maxn], yy[maxn], zz[maxn];
Interval aa[maxn];
ll kk[maxn], rr[maxn];

ll solve() {
  ll N, Q; cin >> N >> Q;
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
    aa[i].start = min(xx[i], yy[i]) + 1;
    aa[i].end = max(xx[i], yy[i]) + 1;
  }

  fori (i, 1, Q + 1) {
    kk[i] = zz[i] + 1;
  } 

  sort(aa + 1, aa + N + 1, cmp);
  reverse(aa + 1, aa + N + 1);

  // fori (i, 1, N + 1) {
  //   trace(aa[i].start, aa[i].end);
  // }

   
  // trace(N, Q);
  // par(aa, N + 1, 1);
  // par(bb, N + 1, 1);
  // par(kk, Q + 1, 1);

  // par(rr, cnt, 1);

  ll cnt = kk[1];
  // cnt = 10;
  // trace(cnt);
  ll mx = aa[1].end;
  for (ll i = mx; i >= 0; --i) {
    // trace(mx, i, cnt);
    for (int j = 1; j < N + 1; ++j) {
      if (aa[j].start <= i && i <= aa[j].end) {
        // trace(aa[j].start, aa[j].end);
        cnt--;
        if (cnt == 0) return i;
      } else if (i < aa[j].start) break;

    }
  }
  return 0;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    ll r = solve();
    codejam(i, r);
  }

  return 0;
}

