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

const int maxn = 100;
char mat[maxn][maxn];
int solve() {
  int n; cin >> n;
  mst(mat, 0);
  fori (i, 1, n + 1) {
    string a; cin >> a;
    fori (j, 1, n + 1)
      mat[i][j] = a[j - 1];
  }
  // Find the center of 'X' symbol.
  int cnt = 0;
  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      if (mat[i][j] != 'X') continue;
      int one = 0;
      fori (k, 1, n + 1) 
        one += mat[i][k] == 'X';
      fori (k, 1, n + 1)
        one += mat[k][j] == 'X';
      if (one == 2) {
        ++cnt;
        mat[i][j] = '.';
      }
    }
  } 
  if (cnt > 1 || cnt == 0) return 0;

  fori (i, 1, n + 1) {
    fori (j, 1, n + 1) {
      if (mat[i][j] != 'X') continue;
      int x = -1, y = -1;
      fori (k, i + 1, n + 1) {
        fori (l, 1, n + 1) {
          if (l != j && mat[k][l] == 'X' && 
              mat[i][l] == 'X' && mat[k][j] == 'X')  {
            if (x == -1)  {
              x = k; y = l;
            } else 
              return 0;
          }
        }
      } 
      if (x == -1)  return 0;
      mat[i][j] = '.';
      mat[x][j] = '.';
      mat[i][y] = '.';
      mat[x][y] = '.';
      cnt += 2;
    }
  }  
  return cnt == n;
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    int r = solve(); 
    codejam(i, r ? "POSSIBLE" : "IMPOSSIBLE"); 
  }

  return 0;
}
