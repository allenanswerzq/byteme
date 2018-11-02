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


int main(int argc, char** argv) {
  int r, c; cin >> r >> c;
  vs gg(r);
  fori (i, 0, r) {
    cin >> gg[i];
  }

  // pvi(gg, 1);
  int visit[r][c]; 
  mst(visit, 0);
  int ret = 0;
  fori (i, 0, r) {
    fori (j, 0, c) {
      if (gg[i][j] == 'S') continue;
      bool ok = 0;
      fori (k, 0, c) if (gg[i][k] == 'S') ok = 1;
      if (!ok) {
        fori (k, 0, c) {
          if (!visit[i][k]) ++ret;
          visit[i][k] = 1;
        }
      }

      ok = 0;
      fori (k, 0, r) if (gg[k][j] == 'S') ok = 1;
      if (!ok) {
        fori (k, 0, r) {
          if (!visit[k][j]) ++ret;
          visit[k][j] = 1;
        }
      }
    } 
  }
  
  outret(ret); 

  return 0;
}

