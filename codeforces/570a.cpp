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

// #define LOCAL_FILE

const int maxn = 110;
int aa[maxn][maxn];
int bb[maxn];
int cc[maxn];
int dd[maxn];

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("570a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n_cand, n_city; cin >> n_cand >> n_city;
  fori (i, 0, n_city) {
    int mx = 0;
    fori (j, 0, n_cand) {
      cin >> aa[i][j];
      mx = max(mx, aa[i][j]);
    }
    bb[i] = mx;
  }

  fori (i, 0, n_city) {
    fori (j, 0, n_cand) {
      if (aa[i][j] == bb[i]) {
        cc[i] = j;
        break;
      }
    }
  }

  fori (i, 0, n_city) dd[cc[i]]++;  

  // par(bb, n_city, 1);
  // par(cc, n_city, 1);
  // par(dd, n_cand, 1);

  int mx = *max_element(dd, dd + n_cand);
  int ret = -1;
  fori (i, 0, n_cand) 
    if (dd[i] == mx) {
      ret = i + 1;
      break;
    }

  outret(ret);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}

