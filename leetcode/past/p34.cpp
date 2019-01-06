#include <bits/stdc++.h>
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

class Solution {
  public:
  vector<int> searchRange(vector<int>& aa, int target) {
    int n = aa.size();
    int lo = 0, hi = n - 1;
    vector<int> ret;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (aa[mid] == target) {
        int i = mid;
        while (i > 0 && aa[i] == aa[i - 1]) --i;
        ret.push_back(i);
        i = mid;
        while (i < n - 1 && aa[i] == aa[i + 1]) ++i;
        ret.push_back(i);
        return ret;
      } else if (aa[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return {-1, -1};
  }
};

void test(vector<int> aa, int bb) {
  Solution go;
  vector<int> res = go.searchRange(aa, bb);
  pvi(res);
}

int main() {
  test({0,0,2,3,4,4,4,5}, 4);
  return 0;
}
