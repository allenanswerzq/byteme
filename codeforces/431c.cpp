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
const int mod = 1e9 + 7;
int dp[120][2];

void add(int& a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main(int argc, char** argv) {
  int n, k, d; cin >> n >> k >> d;
  // trace(n, k, d);
  dp[0][0] = 1;
  dp[0][1] = 0;

  fori (i, 1, n + 1) {
    dp[i][0] = dp[i][1] = 0;
    fori (j, 1, k + 1) {
      if (i - j < 0) break;
      // trace(i, j);
      if (j < d) {
        add(dp[i][0], dp[i-j][0]);
        add(dp[i][1], dp[i-j][1]);
      } else {
        add(dp[i][1], dp[i-j][0]);
        add(dp[i][1], dp[i-j][1]);
      }
    }
  }

  // fori (i, 0, n + 1) {
  //   par(dp[i], 2, 1);
  // }

  output(dp[n][1]);
  return 0;
}

