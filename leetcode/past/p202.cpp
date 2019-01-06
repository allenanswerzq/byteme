#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isHappy(int inp) {
    map<int, int> mp;        
    int sum = 0;
    while (sum != 1 && mp.count(inp)) {
      string a = to_string(inp);
      for (int i = 0; i < a.size(); ++i)
        sum += (a[i] - '0') * (a[i] - '0');
      mp[inp] = sum;
      inp = sum;
    }
    return sum == 1;
  }
};

int main() {
  return 0;
}
