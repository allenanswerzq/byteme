#include<bits/stdc++.h>
using namespace std;

// aaccepted
void setZeroes(vector<vector<int>>& aa) {
  int m=aa.size(), n=aa[0].size();
  // extra space O(m+n)
  vector<bool> r(m, false);   // mark row
  vector<bool> c(n, false);   // mark column 
  for (int i=0; i<m; ++i)
  for (int j=0; j<n; ++j)
  if(aa[i][j] == 0) {
  r[i] = true;
  c[j] = true;
  }
  for (int i=0; i<m; ++i)
  for (int j=0; j<n; ++j)
  if (r[i] || c[j])
    aa[i][j] = 0;
  return;
}

// no extra space
void setZeroes(vector<vector<int>>& aa) {
  int m=aa.size(), n=aa[0].size();
  bool col0 = false;
  for (int i=0; i<m; ++i) {
  if (aa[i][0] == 0) col0 = true;
  for (int j=1; j<n; ++j)
  if(aa[i][j] == 0) {
    aa[i][0] = 0;
    aa[0][j] = 0; 
  }
  }

  for (int i=m-1; i>=0; --i) {
  for (int j=n-1; j>=1; --j)
  if (aa[i][0]==0 || aa[0][j]==0) 
   aa[i][j] = 0; 
  if(col0) aa[i][0] = 0;
  }
  
  return;
}

int main(int argc, char** argv) {
  return 0;
}
