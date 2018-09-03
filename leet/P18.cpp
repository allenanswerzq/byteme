#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
public:
  vvi fourSum(vector<int>& aa, int target) {
    vvi ret;
    if (aa.size() < 4) return ret;
    sort(all(aa));
    int n = aa.size();
    // a + b + c + d = target 
    // b + c + d = target - a For each a
    for (int i = 0; i < n; ++i) {
      if (i > 0 && aa[i] == aa[i - 1]) continue;
      int sum = target - aa[i];
      for (int j = i + 1; j < n - 2;) {
        int a = aa[j];
        int lo = j + 1, hi = n - 1;
        while (lo < hi) {
          int b = aa[lo];
          int c = aa[hi];
          if (a + b + c == sum) {
            vector<int> t = {aa[i], a, b, c};
            ret.push_back(t);
            while (lo<n-1 && aa[lo] == aa[lo+1]) ++lo;
            while (hi>0 && aa[hi] == aa[hi-1]) --hi;
            ++lo;
            --hi;
          } else if (a + b + c > sum){
            while (hi > 0 && aa[hi] == aa[hi-1]) --hi;
            --hi;
          } else {
            while (lo < n - 1 && aa[lo] == aa[lo + 1]) ++lo;
            ++lo;
          }
        }
        while (j < n - 2 && aa[j] == aa[j + 1]) ++j;
        ++j;
      }
    }
    return ret; 
  }
};

void test(vi aa, int bb) {
  Solution go;
  vvi res = go.fourSum(aa, bb);
  fora (r, res) {
    pvi(r);
  }
}

int main() {
  test({-1,0,1,2,-1,-4}, -1);
  return 0;
}
