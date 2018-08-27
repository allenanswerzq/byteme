#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>
#define pii pair<int, int>
#define vpii vector<pair<int,int>>

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))

#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
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

// #define LOCAL_FILE

vs aa;
bool check(string a, string b) {
  if (sz(a) != sz(b)) return 0;
  map<char, int> mp;
  fora (c, a) mp[c]++;
  fora (c, b) mp[c]--;
  fora (a, mp) if (a.se != 0) return 0; 
  int n = sz(a);
  int ix = -1;
  fori (i, 0, n)
    if (a[0] == b[i]) {
      ix = i;
      break;
    } 
  if (ix == -1) return 0;
  if (ix < n-1 && b[ix + 1] == a[1]) {
    int k = ix;
    fori (i, 1, )
    return 0;
  } else if (ix>1 && b[ix - 1] == a[1]) {
    return 1;
  }
  return 0;
}

bool solve() {
  int n = sz(aa);
  fori (i, 0, n) {
    fori (j, i + 1, n)
      if (check(aa[i], aa[j]))
        return 1;
  }
  return 0;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("c-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int x; cin >> x;
    fori (j, 1, x + 1) {
      string inp; cin >> inp;
      aa.pb(inp);
    }  
    int r = solve();
    string out = r ? "Yeah" : "Sad";
    cout << out << endl;

  }  

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
