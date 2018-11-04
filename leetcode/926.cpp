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
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
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
  static clock_t old;
  clock_t now = clock();
  double diff = 1.0 * (now - old);
  diff /= CLOCKS_PER_SEC;
  old = now;
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

const int maxn = 22000;
int dp[maxn][2];

class Solution {
public:
  int minFlipsMonoIncr(string ss) {
    int n = sz(ss);      
    if (ss[0] == '0') {
      dp[0][0] = 0;
      dp[0][1] = 1;
    } else {
      dp[0][1] = 0;
      dp[0][0] = 1;
    }

    fori (i, 1, n) {
      if (ss[i] == '1') {
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = dp[i-1][0] + 1;
      } else {
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
        dp[i][0] = dp[i-1][0];
      }
    } 

    // trace(ss);
    // fori (i, 0, n) {
    //   par(dp[i], 2, 1);
    // }
    int r = min(dp[n-1][0], dp[n-1][1]);
    return r;
  }
};

void test(string ss) {
  Solution go;
  int r = go.minFlipsMonoIncr(ss);
  output(r);
}

int main() {
 
  test("00110");
  test("010110");
  test("00011000");
  test("100000001010000");

  return 0;
}

