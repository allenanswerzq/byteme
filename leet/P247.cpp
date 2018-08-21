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

// Strobogrammatic Number II return all the Strobogrammatic Numbers with length n
vector<string> findStrobogrammatic(int n) {
  vector<string> ret;
  vector<string> template = {"00", "11", "88", "96", "69"};
  if (n & 1) ret = {"0", "1", "8"};
  while (n > 1) {
    n -= 2;  // each time add two characters on both sides of ret string
    vector<string> tmp;
    for (auto s : ret)
      for (int i=0; i<tmplate.size(); ++i)
        tmp.push_back(template[i][0] + s + tmplate[i][1]); 
    ret = tmp;
  }
  return ret;
}
