#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (matrix.size() <= 0) return false; 
  int m = matrix.size(), n = matrix[0].size(); 
  // Starting from top-right corner
  int r = 0, c = n-1;
  while (r<m && c>=0) {
    if (matrix[r][c] == target) return true;
    if (matrix[r][c] < target) r++;
    else c--;
  }   
  return false;
}
