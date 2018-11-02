#include<bits/stdc++.h>
using namespace std;

class CakeType {
public:
  int weight;
  long long value;

  CakeType(int weight=0, long long value=0):
    weight(weight),
    value(value) {}
};

// dp[0] = 0
// dp[w] = max(vi + dp[w-wi])
// Time O(n*k)
// Space O(k)
int maxDuffelBagValue(vector<CakeType> cakes, int capacity) {
  long long dp[capacity+1];
  mst(dp, 0);
  for (int i = 1; i <= capacity; ++i) {
    for (auto cake : cakes) {
      if (cake.weight == 0 && cake.value != 0) {
        printf("max value is inifinity");
        return -1;
      }
      if (i >= cake.weight)
        dp[i] = max(dp[i], cake.value + dp[i-cake.weight]);
    }
  }
  return dp[capacity];
}

int main() {
  return 0;
}
