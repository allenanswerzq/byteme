#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
  vvi res;
  for(int i=0; i<sz(S); ) {
  int j = i;
  while(j < sz(S)-1 && S[j] == S[j+1]) ++j;
  if (j - i + 1 >= 3) {
  res.pb({i, j});
  }
  i = j+1;
  }      
  return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
