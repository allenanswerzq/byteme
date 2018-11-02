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

// #define LOCAL_FILE
// TODO

ll cal(ll aa) {
  ll ret = 0;
  string ss = to_string(aa);
  fori (i, 0, sz(ss)) {
    ret += (ss[i] - '0');
  }
  return ret;
}

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("b-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  ll n; cin >> n >> ws;
  ll cur = 0;
  ll ret = 0;
  while (n >= cur * 10 + 9) {
    cur = cur * 10 + 9;
    ret += 9;
  }

  // trace(cur, n - cur);
  n -= cur;
  while (n) {
    ret += n % 10;
    n /= 10;
  }
  // ll ret = cal(cur) + cal(n - cur);
  outret(ret);


#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}

