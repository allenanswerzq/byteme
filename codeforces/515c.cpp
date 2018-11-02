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
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define LOCAL_FILE
// TODO
int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("515c-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  vi dp(10, 0);
  int n; cin >> n;
  int mx = 0;
  fori (i, 0, n) {
    char x; cin >> x;
    int y = x - '0';  
    mx = max(mx, y);
    fori (i, 1, y + 1) 
      dp[i]++;
  }

  // pvi(dp, 1);

  int pre = 0;
  set<int> st{4, 6, 8, 9};
  ford (k, mx, 3) {
    if (dp[k] && dp[k] > pre && st.count(k)) {

      if (k == 8) {
        dp[2] += (dp[k] - pre) * 3;

      } else if (k == 4) {
        dp[2] += (dp[k] - pre) * 2;

      } else if (k == 6) {
        dp[2] += dp[k] - pre;
        dp[3] += dp[k] - pre;

      } else if (k == 9) {
        dp[3] += (dp[k] - pre) * 2;
      }
      dp[k] = pre;
    } 
    pre = dp[k];
  }

  // pvi(dp, 1);

  string ret;
  ford (i, 9, 1) {
    while (dp[i]) {
      ret += char(i + '0');
      ford (j, i, 1) 
        --dp[j]; 
    }
  }

  // trace(ret);
  outret(ret);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}

