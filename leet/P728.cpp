#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
  printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
  printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
  n = n&(n-1);
  count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

bool helper(int x) {
  int y = x;
  while (x) {
  int t = x%10;
  if(y % t) return false;
  x /= 10;
  } 
  return x==0 ? false: true;
}

vector<int> selfDividingNumbers(int left, int right) {
  vector<int> ret;
  for (int i=left; i<=right; ++i)
  if (helper(i))
  ret.push_back(i); 
  return ret;
}
