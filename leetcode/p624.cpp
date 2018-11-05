#include <bits/stdc++.h>
using namespace std;

// naive approach 
// O(n2) complexity
int maxDistance(vector<vector<int>>& A) {
  int res=0, n=A.size();
  for (int i=0; i<n; ++i) 
    for (int j=i+1; j<n; ++j) {
      int a = abs(A[i][0] - A[j][A[j].size()-1]);
      res = max(res, a);
      a = abs(A[j][0] - A[i][A[i].size()-1]);
      res = max(res, a);
    }
  return res;
}

int maxDistance(vector<vector<int>>& A) {
  int res=0, n=A.size();
  int mi=A[0].front(), mx=A[0].back();
  for (int i=1; i<n; ++i) {
    // should notice that A is ascending order
    res = max(res, abs(mi-A[i].back()));
    res = max(res, abs(mx-A[i].front()));
    mi = min(mi, A[i].front());
    mx = max(mx, A[i].back());
  }
  return res;
}

int main() {
  return 0;
}
