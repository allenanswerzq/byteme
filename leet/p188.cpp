#include<bits/stdc++.h>
using namespace std;

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
  int maxProfit(int k, vector<int> &prices) {
  if (prices.empty()) return 0;
  if (k >= prices.size()) return solveMaxProfit(prices);
  int global[k + 1] = {0};
  int local[k + 1] = {0};
  for (int i = 0; i < prices.size() - 1; ++i) {
    int diff = prices[i + 1] - prices[i];
    for (int j = k; j >= 1; --j) {
    local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
    global[j] = max(global[j], local[j]);
    }
  }
  return global[k];
  }
  
  int solveMaxProfit(vector<int> &prices) {
  int res = 0;
  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] - prices[i - 1] > 0) {
    res += prices[i] - prices[i - 1];
    }
  }
  return res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p188-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
