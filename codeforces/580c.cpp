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


#define maxn 100005
int cats[maxn];
vi dp[maxn];
int ret;
int n_vtc, n_cats; 

void dfs(int uu, int parent, int path) {

  // trace(uu, parent, cats[uu], path, n_cats);
  if (path > n_cats) {
    return; 
  }

  // trace(sz(dp[uu]));
  if (sz(dp[uu]) == 1 && dp[uu][0] == parent) {
    if (path + cats[uu] <= n_cats) {
      // trace("ret", uu);
      ++ret;
    }
    return; 
  }

  int pre = cats[parent];
  if (pre && cats[uu]) ++path;
  else if (!pre && cats[uu]) path = 1;
  else path = 0;

  fora (v, dp[uu]) {
    if (v == parent) continue;
    // trace(uu, v, path, pre);
    dfs(v, uu, path); 
  }
}

int main(int argc, char** argv) {
  cin >> n_vtc >> n_cats;
  fori (i, 1, n_vtc + 1) {
    cin >> cats[i];
  } 

  fori (i, 1, n_vtc) {
    int x, y; cin >> x >> y;
    dp[x].pb(y);
    dp[y].pb(x);
  }

  // par(cats, n_vtc + 1, 1);
  // fori (i, 1, n_vtc + 1) {
  //   pvi(dp[i], 1);
  // }
  
  ret = 0;  
  cats[0] = 0;
  dfs(1, 0, 0);
  outret(ret);

  return 0;
}

