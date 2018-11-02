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


#define maxn 1010
int aa[maxn];
int sa, sb;

void solve(int lo, int hi, int flag) {
  if (lo > hi) return ;
  bool side = 0; 
  int mx = 0;
  if (aa[lo] > aa[hi]) {
    mx = aa[lo]; side = 0;
  } else {
    mx = aa[hi]; side = 1;
  }

  if (!flag) sa += mx;
  else sb += mx;

  if (side) solve(lo, hi - 1, 1 - flag);
  else solve(lo + 1, hi , 1 - flag);

}

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    cin >> aa[i];
  }

  // sa = sb = 0;
  // solve(1, n, 0);
  // cout << sa << " " << sb << endl;

  sa = sb = 0;
  int lo = 1, hi = n;
  bool turn = 0;
  while (lo <= hi) {
    int mx = max(aa[lo], aa[hi]);
    if (turn) sb += mx;
    else sa += mx; 
    if (mx == aa[lo]) ++lo;
    else --hi; 
    turn = 1 - turn;
  }

  cout << sa << " " << sb << endl;

  return 0;
}

