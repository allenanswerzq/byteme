#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
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

// #define LOCAL_FILE
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

const int mod = 1e9 + 7;
vs gg;
vvi dp;
int h, w;

void solve() {
  ford (i, h - 1, -1) 
    ford (j, w - 1, -1) {
      if (i == h - 1 && j == w - 1)
        dp[i][j] = 1; 
      else {
        if (gg[i][j] == '#') continue; 
        int ret = 0;
        if (0<=i && i + 1 < h) 
          ret += (dp[i + 1][j]) % mod;
        if (0<=j && j + 1 < w)
          ret += (dp[i][j + 1]) % mod; 
        dp[i][j] = ret % mod;
      }
    }
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("b-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 
  cin >> h >> w >> ws;
  // trace(h, w);
  fori (i, 1, h + 1) {
    string t; cin >> t;
    // trace(t);
    gg.push_back(t); 
  }  
  dp.resize(h, vi(w, 0));
  solve();
  // dfs(0);

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int x, y; cin >> x >> y;
    // int a = (x - 1) * w + (y - 1);
    // trace(x, y, a);
    cout << dp[x-1][y-1] << endl;
  }


#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
