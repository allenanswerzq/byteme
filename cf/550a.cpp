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

bool check(string ss, string aa, string bb) {
  int x = ss.find(aa);
  if (x == string::npos) return 0;
  if (ss.find(bb, x + 2) == string::npos) return 0;
  return 1;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  // freopen("550a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  string ss; cin >> ss;
  bool aa, bb;
  aa = bb = 0;
  fori (i, 1, sz(ss)) {
    if (ss[i] == 'A' && ss[i-1] == 'B') {
      if (aa == 1) {
        bb = 1;
        break;
      }
    }

    if (ss[i] == 'B' && ss[i-1] == 'A') {
      if (bb == 1) {
        aa = 1;
        break;
      }
    }

    if (i > 1) {
      if (ss[i-1] == 'B' && ss[i-2] == 'A') aa = 1;
      if (ss[i-1] == 'A' && ss[i-2] == 'B') bb = 1; 
    } 
  }

  outret(aa && bb ? "YES" : "NO");

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
