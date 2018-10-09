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
#define vvi vector<vi>

class Solution {
public:
  // O(n) solution
  // Siliding window
  int minSubArrayLen(int goal, vi& aa) {
    int sum = 0, lo = 0;
    int res = (1 << 30);
    for (int i = 0; i < sz(aa); ++i) {
      sum += aa[i];
      while (sum >= goal) {
        res = min(res, i - lo + 1);
        sum -= aa[lo++];
      }
    } 
    return res == (1<<30) ? 0: res;
  }

  // O(nlogn)
  int minSubArrayLen(int goal, vi& aa) {
    int n = aa.size();
    vi pre_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pre_sum[i] = pre_sum[i-1] + aa[i-1];

    int res = (1<<30);
    fori (i, 1, n + 1) {
      if (pre_sum[i] >= goal) {
        auto it = upper_bound(all(pre_sum), pre_sum[i] - goal);
        int p = distance(pre_sum.begin(), it);
        if (p >= 0) res = min(res, i - (p - 1));  
      } 
    }
    return res == (1<<30) ? 0 : res;
  }
};

void test(int kk, vi aa) {
  Solution go;
  int ret = go.minSubArrayLen(kk, aa);
  output(1, ret);
}

int main(int argc, char** argv) {
  test(7, {2, 3, 1, 2, 4, 3});
  return 0;
}
