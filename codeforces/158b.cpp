#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl

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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main(int argc, char** argv) {
  vi dp(5, 0);
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    int x; cin >> x;
    if (x == 1) dp[1]++;
    if (x == 2) dp[2]++;
    if (x == 3) dp[3]++;
    if (x == 4) dp[4]++; 
  }

  // par(dp, 5);

  int ret = dp[4];
  ret += (dp[2] + 2 - 1) / 2;
  if (dp[3] >= dp[1]) {
    ret += dp[3];
    dp[1] = 0;
  } else {
    ret += dp[3];
    dp[1] = dp[1] - dp[3];
  }
  if (dp[1] && dp[2] % 2) dp[1] -= 2;
  if (dp[1] > 0) ret += (dp[1] + 4 - 1) / 4;
  output(ret);

  return 0;
}
