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

int nthUglyNumber(int n) {
  vector<int> ugly(n, 1);
  int i2=0, i3=0, i5=0;
  for (int i=1; i<n; ++i) {
    int cur_max = ugly[i-1];
    while (ugly[i2]*2 <= cur_max) i2++;
    while (ugly[i3]*3 <= cur_max) i3++;
    while (ugly[i5]*5 <= cur_max) i5++;
    ugly[i] = min(min(ugly[i2]*2, ugly[i3]*3), ugly[i5]*5);
  }
  return ugly[n-1];
}
