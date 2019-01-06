#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
  vector<int> plusOne(vector<int>& aa) {
    int i = aa.size() - 1;
    int c = 0;
    while (i >= 0) {
      if (i == aa.size() - 1) c += aa[i] + 1;
      else c += aa[i];
      aa[i--] = c % 10;
      c /= 10;
    }
    if (c) aa.insert(aa.begin(), 1);
    return aa;
  }
};

int main() {
  return 0;
}
