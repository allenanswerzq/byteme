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

int n, m;
vector<vector<char>> dp;

int main(int argc, char** argv) {
  cin >> n >> m;
  dp.resize(n, vector<char>(m, '.'));

  bool flag = 0;
  fori (i, 0, n) {
    if (i % 2 == 0) fori (j, 0, m) dp[i][j] = '#';
    else {
      if (flag == 0) {dp[i][m-1] = '#'; flag = 1;}
      else if (flag == 1) {dp[i][0] = '#', flag = 0;}
    }
  } 

  fori (i, 0, n) {
    fori (j, 0, m) {
      cout << dp[i][j];
    }
    cout << endl;
  }

  return 0;
}
