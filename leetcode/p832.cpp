#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    vvi res;
    fora (v, A) {
      vi tmp;
      for (auto it=v.rbegin(); it < v.rend(); ++it) {
        tmp.pb(*it ^ 1)
      }
      res.pb(tmp);
    }
    return res;
  }
};

int main() {
  return 0;
}
