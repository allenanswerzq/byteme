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
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
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
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define LOCAL_FILE

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("118b-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n; cin >> n;
  int r = 2 * n + 1;
  int m = 4 * n + 1;
  int dp[r][m];
  mst(dp, -1);
  ford (i, n, -1) {
    int c = i, cnt = i + 1;
    for (int j = 2 * n; cnt; j -= 2) {
      dp[i][j] = c--; 
      --cnt;
    } 

    c = i; cnt = i + 1;
    int j = 2 * n;
    for (; cnt; j += 2) {
      dp[i][j] = c--;
      --cnt;
    }
    for (j -= 1; j < m; ++j) dp[i][j] = -4;
  } 

  fori (i, n, r) {
    int c = 2 * n - i, cnt = 2 * n - i + 1;
    for (int j = 2 * n; cnt; j -= 2) {
      dp[i][j] = c--; 
      --cnt;
    } 

    c = 2 * n - i; cnt = 2 * n - i + 1;
    int j = 2 * n;
    for (; cnt; j += 2) {
      dp[i][j] = c--;
      --cnt;
    }
    for (j -= 1; j < m; ++j) dp[i][j] = -4;
  } 

  fori (i, 0, r) {
    fori (j, 0, m) {
      if (dp[i][j] == -1) cout << " ";
      else if (dp[i][j] != -4) cout << dp[i][j];
    }
    cout << endl;
  }

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}

