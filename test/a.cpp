#include<bits/stdc++.h>
using namespace std;

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
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("a-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  int n, q; cin >> n >> q >> ws;
  vi inp(n + 1, 0);
  vi tmp(n + 1, 0);
  vi ret;
  vpii bb;
  unordered_set<int> st;
  fori (i, 1, n + 1) {
    cin >> inp[i];
  }  

  fori (i, 1, q + 1) {
    int a, b; cin >> a >> b;
    // trace(a, b);
    bb.push_back({a, b});
  }

  // pvi(inp);
  int sum = 0;
  fori (i, 0, sz(inp))
    if (inp[i] % 2 == 0) {
      st.insert(i);
      sum += inp[i];
    }

  // trace(sum); 

  fora (it, bb) {
    int id = it.first, val = it.second; 
    // trace(id, val);

    if (st.count(id)) {
      if ((inp[id] + val) % 2 == 0) {
        sum += val;
      } else {
        sum -= inp[id];
      }
    } else {
      if ((inp[id] + val) % 2 == 0) {
        st.insert(id);
        sum += (inp[id] + val);
      }
    }
    ret.push_back(sum);
    inp[id] += val;
    if (inp[id] % 2) st.erase(id);
    // trace(sum); 
  } 

  fora (r, ret)
    cout << r << endl;


#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
