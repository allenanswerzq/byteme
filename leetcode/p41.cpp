#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& aa, int n) {
    for (int i = 0; i < n; ++ i)
      while (0 < aa[i] && aa[i] <= n && aa[aa[i] - 1] != aa[i])
        swap(aa[i], aa[aa[i] - 1]);

    for (int i = 0; i < n; ++ i)
      if (aa[i] != i + 1)
        return i + 1;

    return n + 1;
  }
};

int main() {
  return 0;
}
