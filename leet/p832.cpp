#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    vvi res;
    fora(v, A) {
      vi tmp;
      for (auto it=v.rbegin(); it < v.rend(); ++it) {
        tmp.pb(*it ^ 1)
      }
      res.pb(tmp);
    }    
    return res;
  }
};



int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
