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

// TODO
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = sz(prices);
    int res = 0;
    int sum = 0;
    fori (i, 0, n - 1) {
      int diff = prices[i + 1] - prices[i];
      sum = max(diff, sum + diff);
      res = max(res, sum);
    }
    return res;
  }

  int maxProfit2(vi& prices) {
    int n = sz(prices);
    int mi = (1 << 30);
    int res = 0;
    fori (i, 0, n) {
      mi = min(mi, prices[i]);
      res = max(res, prices[i] - mi);
    } 
    return res;
  }
};

void test(vi inp) {
  Solution go;
  cout << go.maxProfit(inp) << "\n";
}

int main() {
 
  test({7, 1, 5, 3, 6, 4});
  test({7, 6, 5, 4, 3});
  test({2, 4, 1});

  return 0;
}
