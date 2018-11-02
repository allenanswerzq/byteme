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


#define maxn 2002
vi gg[maxn];
int visit[maxn];

int dfs(int uu) {
  if (sz(gg[uu]) == 0) return 1;
  int ret = 0;
  fora (vv, gg[uu]) {
    ret = max(ret, dfs(vv) + 1);
  }
  return ret;
}

int main(int argc, char** argv) {
  int n; cin >> n;
  fori (i, 1, n + 1) {
    int a; cin >> a;
    if (a != -1) gg[a].pb(i); 
  }

  // fori (i, 1, n + 1) {
  //   pvi(gg[i], 1);
  // }

  mst(visit, 0);
  int ret = 0;
  fori (i, 1, n + 1) {
    if (!visit[i])
      ret = max(ret, dfs(i));
  }
  outret(ret); 

  return 0;
}

