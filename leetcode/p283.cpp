#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& aa){ 
    int k = 0;
    for (auto& a : aa)
      if (a) 
        aa[k++] = a;

    for (int i = k; i < aa.size(); ++i)
      aa[i] = 0;
  }
};

void test(vi aa) {
  Solution go;
  go.moveZeroes(aa);
  pvi(aa);
}

int main() {
  test({0, 1, 0, 3, 12});
}
