#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& aa){ 
  int k = 0;
  for (auto& a : aa)
    if (a) 
      aa[k++] = a;

  for (int i = k; i < aa.size(); ++i)
    aa[i] = 0;
}

int main() {
  vector<int> aa{0, 1, 0, 3, 12};
  moveZeroes(aa);
  for (auto v: aa)
    cout << v << "\n";
}
