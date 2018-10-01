#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(val) cout << (val) << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) cout<< #x << ": "; fori(a, 0, n) cout<<x[a]<<" "; cout <<endl

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
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define LOCAL_FILE

// TODO
int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  // freopen("466c-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n; cin >> n >> ws;
  vi aa(n + 1, 0); 
  vl pre_sum(n + 1, 0);
  fori (i, 1, n + 1) {
    cin >> aa[i];
    pre_sum[i] = pre_sum[i - 1] + aa[i];
  }

  // pvi(aa);
  // pvi(pre_sum);

  if (pre_sum[n] % 3) {
    outret(0); 
    return 0;
  } 

  vi p1, p2;
  ll val = pre_sum[n] / 3;
  fori (i, 1, n) {
    if (pre_sum[i] == val && i <= n - 2)
      p1.pb(i);
    if (pre_sum[i] == 2 * val && 2 <= i && i <= n - 1)
      p2.pb(i);
  }

  // pvi(p1);
  // pvi(p2);

  ll ret = 0;
  fori (i, 0, sz(p1)) {
    ll p = distance(p2.begin(), upper_bound(all(p2), p1[i]));
    // trace(p);
    ret += (sz(p2) - p);
  }

  outret(ret);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
