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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


const int maxn = 2000;
int dp[maxn];
int n, m, a, b; 
int solve(int n) {
  if (dp[n] != -1) return dp[n];
  if (n <= 0) return 0;
  if (n <= m) return min(n * a, b);
  int x = solve(n - 1) + a;
  int y = solve(n - m) + b;
  // trace(n, m, a, b, x, y);
  dp[n] = min(x, y);
  return dp[n];
}

int main(int argc, char** argv) {
  cin >> n >> m >> a >> b;
  mst(dp, -1);
  dp[0] = 0;
  int ret = solve(n);
  outret(ret);

  return 0;
}
