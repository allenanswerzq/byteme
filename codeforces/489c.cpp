#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

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
// TODO
int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  // freopen("489c-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  int m, s; cin >> m >> s;
  string s1, s2;
  // trace(m, s);
  if (m == 1 && s == 0) { 
    s1 = "0"; s2 = "0"; 
  } else if (s <= 0 || s > m * 9) { 
    s1 = "-1"; s2 = "-1"; 
  } else {
    fori (i, 0, m) {
      int d = min(9, s);
      s = s - d;
      s1 += ('0' + d);
    }

    s2 = s1;
    reverse(all(s2));

    if (s2[0] == '0') {
      fori (i, 0, m) 
        if (s2[i] > '0') {
          ++s2[0];
          --s2[i];
          break;
        }
    }
  }

  cout << s2 << " " << s1 << endl;

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
