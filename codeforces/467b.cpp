#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(val) cout << (val) << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) cout<< #x << ": "; fori(a, 0, n) cout<<x[a]<<" "; cout <<endl

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

// #define LOCAL_FILE

bool check(int a, int b, int k) {
  int ret = 0;
  fori (i, 0, 32) {
    if ((a & 1) != (b & 1)) ++ret;
    a >>= 1;
    b >>= 1;
  } 
  return ret <= k;
}

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("467b-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n, m, k; cin >> n >> m >> k;
  vi aa(m + 1, 0);
  fori (i, 0, m + 1) {
    cin >> aa[i]; 
  }

  int fedor = aa[m]; 
  int ret = 0; 
  fori (i, 0, sz(aa) - 1) {
    if (check(fedor, aa[i], k)) ++ret;
  }
  outret(ret);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
