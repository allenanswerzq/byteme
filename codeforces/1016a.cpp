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

// TODO
void sovle() {
  int n, m; cin >> n >> m;
  ll r = 0, pre = m, cur = m;
  fori (i, 0, n) {
    int x; cin >> x;
    int y = 0;
    r += x;
    if (r >= pre) {
      cur = r + m - r % m;
      y = (cur - pre) / m;
    }
    pre = cur;
    // trace(x, y, r, pre, cur);
    cout << y << " ";
  }
  pend;
}

void solve2() {
  int n, m; cin >> n >> m;
  vi aa(n, 0);
  fori (i, 0, n) cin >> aa[i];
  ll cur = 0;
  fori (i, 0, n) {
    cur += aa[i];
    cout << cur / m << " ";
    cur %= m; 
    trace(aa[i], cur, m);
  }
  pend;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  solve2();
  return 0;
}

