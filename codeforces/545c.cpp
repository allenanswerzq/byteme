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

const int maxn = 10e5 + 10;
int dp[maxn][3];
pii aa[maxn];

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    cin >> aa[i].first;
    cin >> aa[i].second;
  }

  dp[1][0] = 0;
  dp[1][1] = dp[1][2] = 1;
  fori (i, 2, n + 1) {

    int px = aa[i-1].first, ph = aa[i-1].second;
    int x = aa[i].first, h = aa[i].second;

      
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);

    if (px + ph < x) 
      dp[i][0] = max(dp[i-1][2], dp[i][0]);

    // trace(px, ph, x, h);

    // Previous tree fell into the left side.
    if (x - h > px) {
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
    }

    // Previous tree fell into the right side.
    if (px + ph < x - h) {
      dp[i][1] = max(dp[i-1][2] + 1, dp[i][1]);
    }

    if (x > px) {
      dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + 1;
    }

    if (px + ph < x) {
      dp[i][2] = max(dp[i-1][2] + 1, dp[i][2]);
    }
  }

  int ret = max(dp[n][0], max(dp[n][1], dp[n][2]));
  outret(ret);

  return 0;
}

