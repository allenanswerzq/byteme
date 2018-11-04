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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// TODO

int comb(int n, int k){
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  int result = n;
  for (int i = 2; i <= k; ++i ) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

int main() {
  string aa, bb; cin >> aa >> bb;
  int da, db;
  da = db = 0;
  fori (i, 0, sz(aa)) 
    if (aa[i] == '+') da += 1;
    else if (aa[i] == '-') da -= 1;

  int cnt = 0;
  fori (i, 0, sz(bb)) 
    if (bb[i] == '+') db += 1;
    else if (bb[i] == '-') db -= 1;
    else if (bb[i] == '?') cnt++;

  double ret = 0;
  if ( !(da > db + cnt || da < db - cnt) ) {
    int d = abs(da - db);
    ret = comb(cnt, d + (cnt - d) / 2) / pow(2, cnt);
  }
  output(ret);

  return 0;
}

