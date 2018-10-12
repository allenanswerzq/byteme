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
#define outret(v) cout << (v) << '\n'
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
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
  static clock_t oldtick;
  clock_t newtick = clock();
  double diff = 1.0 * (newtick - oldtick) / CLOCKS_PER_SEC;
  oldtick = newtick;
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
int aa[105];
int dp[105][4];

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

  // 0: neither
  // 1: sport
  // 2: contest
  // 3: contest or sport 
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    cin >> aa[i];
  }

  fori (i, 1, n + 1) {
    dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
    if (aa[i] == 1 || aa[i] == 3)
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    else dp[i][1] = (1 << 30); 
    if (aa[i] == 2 || aa[i] == 3)
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    else dp[i][2] = (1 << 30);
  }

  outret(min(dp[n][0], min(dp[n][1], dp[n][2])));

  return 0;
}

