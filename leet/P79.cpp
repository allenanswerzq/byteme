#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& A, int x, int y, string word) {
  if(word.size() == 0) return true;
  if(x<0 || y<0 || x>=A.size() || y>=A[0].size() || A[x][y]!=word[0])
  return false; 
  // mark current visited cell
  A[x][y] = 0; 
  string tmp = word.substr(1);
  if (check(A, x, y+1, tmp) || check(A, x, y-1, tmp) ||
  check(A, x-1, y, tmp) || check(A, x+1, y, tmp))
  return true;
  A[x][y] = word[0];
  return false;
}

bool exist(vector<vector<char>>& A, string word) {
  for (int i=0; i<A.size(); ++i)
  for (int j=0; j<A[0].size(); ++j)
    if (check(A, i, j, word)) 
    return true;
  return false;
}

int main(int argc, char** argv) {
  return 0;
}
