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


#define maxn 300100
ll sum[maxn];
ll aa[maxn];

ll solve(int lo, int hi) {
  if (lo == hi) return aa[lo];
  ll ret = 0; 
  ret += sum[hi] - sum[lo - 1];
  ret += solve(lo, lo);
  ret += solve(lo + 1, hi);
  return ret;
}

int main(int argc, char** argv) {
  mst(aa, 0);
  mst(sum, 0);

  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    cin >> aa[i];
  }

  sort(aa + 1, aa + n + 1);

  fori (i, 1, n + 1) 
    sum[i] = sum[i - 1] + aa[i];

  // par(aa, n + 1, 1);
  // par(sum, n + 1, 1);

  ll ret = solve(1, n);
  output(ret);
   

  return 0;
}

