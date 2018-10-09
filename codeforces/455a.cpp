#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// define LOCAL_FILE
// TODO
int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  // freopen("455a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  vi cnt(100005, 0);
  vi dp(100005, 0);
  int t; cin >> t >> ws;
  int mx = 0;
  fori (i, 0, t) {
    int x; cin >> x;
    mx = max(mx, x);
    cnt[x]++;
  }

  // dp[i] denotes the maximum points we can get if 
  // current element is `i`.
  dp[1] = cnt[1];
  fori (i, 2, mx + 1) {
    // If we delete `i`, then `i-1` will also be deleted.  
    dp[i] = max(dp[i], dp[i-2] + cnt[i] * (ll)i);
    // Otherwise, we keep `i`.
    dp[i] = max(dp[i-1], dp[i]);
  }

  outret(dp[mx]);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
