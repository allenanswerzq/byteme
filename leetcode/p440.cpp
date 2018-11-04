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

#define vs vector<string>

 //     1        2        3    ...
 //    /\        /\       /\
 // 10 ...19  20...29  30...39   ....

class Solution {
public:
  // Memory Limit Exceeded. 
  int findKthNumber(int n, int k) {
    vs aa;
    fori (i, 1, n + 1)
      aa.push_back(to_string(i));
    sort(all(aa));
    // pvi(aa);
    return stoi(aa[k - 1]);
  }
};

void test(int n, int k) {
  Solution go;
  int ret = go.findKthNumber(n, k);
  output(1, ret);
}

int main() {
  test(13, 2);
  return 0;
}
