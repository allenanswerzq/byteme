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
int aa[7], bb[7], x[7];
bool check() {
  int ok = 1;
  if (aa[x[2]] != bb[x[4]]) ok = 0;
  if (aa[x[1]] != bb[x[2]] || bb[x[2]] != aa[x[5]]) ok = 0;
  if (bb[x[1]] != aa[x[3]] || aa[x[3]] != bb[x[5]]) ok = 0;
  if (bb[x[3]] != aa[x[6]]) ok = 0;
  return ok;
}

bool dfs(int cur) {
  // trace(cur);
  if (cur == 7) {
    return check();
  }

  if (dfs(cur + 1)) {
    return 1;
  }

  swap(aa[cur], bb[cur]);
  int r = dfs(cur + 1);
  swap(aa[cur], bb[cur]);
  return r;
}

void solve() {
  fori (i, 1, 7) {
    cin >> aa[i] >> bb[i];
    x[i] = i;
  } 

  int ok = 0;
  do {
    if (dfs(1)) {
      ok = 1;
      break;
    }
  } while (next_permutation(x + 1, x + 7));

  output(ok ? "YES" : "NO");
}

int main() {
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    solve();
  }
  return 0;
}

