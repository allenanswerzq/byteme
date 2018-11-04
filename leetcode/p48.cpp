#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& aa) {
    reverse(all(aa));
    int n = sz(aa);
    fori (i, 0, n) {
      fori (j, i + 1, n)
        swap(aa[i][j], aa[j][i]);
    }
  }
};

int main() {
  return 0;
}
