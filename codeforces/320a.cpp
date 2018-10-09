#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
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

bool dfs(string ss) {
  if (sz(ss) == 0) return 1;
  bool ret = 0;
  if (sz(ss) >= 1 && ss.substr(0, 1) == "1")
    ret |= dfs(ss.substr(1));
  if (sz(ss) >= 2 && ss.substr(0, 2) == "14")
    ret |= dfs(ss.substr(2));
  if (sz(ss) >= 3 && ss.substr(0, 3) == "144")
    ret |= dfs(ss.substr(3));
  return ret;
}

bool check(int n) {
  if (n == 1 || n == 14 || n == 144) return 1;
  if (n % 10 == 1 && check(n / 10)) return 1;
  if (n % 100 == 14 && check(n / 100)) return 1;
  if (n % 1000 == 144 && check(n / 1000)) return 1;
  return 0;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef EXTERNAL
  // freopen("320a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  string ss; cin >> ss;
  outret(dfs(ss) ? "YES" : "NO");

#ifdef EXTERNAL
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}

