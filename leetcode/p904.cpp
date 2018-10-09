#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl;
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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
  int totalFruit(vector<int>& aa) {
    int ret = 0;
    fori (i, 0, sz(aa)) {
      if (i > 0 && aa[i] == aa[i-1]) continue;
      unordered_set<int> st;
      int lo = i;
      fori (j, i, sz(aa)) {
        if (sz(st) == 2 && !st.count(aa[j])) break;
        st.insert(aa[j]);
        ret = max(ret, j - lo + 1);
        if (j == sz(aa) - 1) 
          return ret;
      }
    } 
    return ret;
  }
};

void test(vi aa) {
  Solution go;
  int ret = go.totalFruit(aa);
  outret(ret);
}

int main(int argc, char** argv) {
  test({1 ,2, 1});
  test({0, 1, 2, 2});
  test({1, 2, 3, 2, 2});
  test({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4});
}
