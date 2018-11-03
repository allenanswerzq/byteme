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
#define output(v) cout << (v) << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
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


#define maxn 10000
vvi gg;
int dp[maxn];
int visit[maxn];

int dfs(int src) {
  int n = sz(gg);
  if (src == n * n) {
    dp[src] = 0;
    return 0;
  }

  if (visit[src]) return dp[src];
  visit[src] = 1;

  int x = n - (src + n - 1) / n + 1, y;
  if (x % 2 == 0) {
    y = src % n;
    if (y == 0) y = n;
  } else {
    y = n - src % n + 1;
    if (y == n + 1) y = 1;
  }

  x -= 1; y -= 1;

  trace(src, x, y);
  if (!(0 <= x && x < n && 0 <= y && y < n)) 
    return (1 << 30);

  int ret = (1 << 30);
  if (gg[x][y] != -1 && visit[gg[x][y]] == 0) 
    ret = min(ret, dfs(gg[x][y]) + 1);

  fori (i, 1, 7) {
    if (src + i <= n * n) {
      int tmp = dfs(src + i) + i; 
      trace(src, i, src + i, tmp);
      ret = min(ret, tmp);
    }
  }    
  trace(src, x, y, ret);

  return dp[src] = ret;
}


class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& aa) {
    gg = aa;
    mst(dp, 0);
    mst(visit, 0);
    int ret = dfs(1);
    trace(ret);
    return ret;
  }
};

void test(vvi gg) {
  Solution go;
  int ret = go.snakesAndLadders(gg);
  output(ret);
}

int main(int argc, char** argv) {
  vvi gg = {{-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1},
            {-1,35,-1,-1,13,-1},
            {-1,-1,-1,-1,-1,-1},
            {-1,15,-1,-1,-1,-1}};
  test(gg);
  return 0;
}

