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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define LOCAL_FILE

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("349a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int n; cin >> n;
  int aa, bb, cc;
  aa = bb = cc = 0;
  string ret = "YES";
  fori (i, 0, n) {
    int a; cin >> a;
    if (a == 25) ++aa;
    else if (a == 50) {
      if (aa == 0) {
        ret = "NO";
        break;
      }
      --aa; ++bb;
    } else if (a == 100) {
      if (bb) {
        if (aa == 0) { ret = "NO"; break; }
        --bb; --aa;
      } else if (aa) {
        if (aa < 3) { ret = "NO"; break; } 
        aa -= 3;
      } else {
        ret = "NO";
        break;
      }
    }
  }
  outret(ret);
   
#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
