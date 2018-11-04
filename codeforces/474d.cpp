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
#define outjam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// TODO
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
int dp[maxn];
int sum[maxn];

int add(int a, int b) {
  int c = a + b;
  if (c >= mod) 
    c -= mod;
  return c;
}

int main() {
  int t, k; cin >> t >> k;

  dp[0] = 1;
  fori (i, 1, maxn) {
    dp[i] = dp[i - 1];
    if (i >= k) {
      dp[i] = add(dp[i], dp[i - k]);
    }
  }
  
  sum[0] = 0; 
  fori (i, 1, maxn) {
    sum[i] = add(sum[i - 1], dp[i]);
  }

  while (t--) {
    int a, b; cin >> a >> b;
    int ret = (sum[b] - sum[a - 1] + mod) % mod;
    output(ret);
  }

  return 0;
}

