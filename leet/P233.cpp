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

// Very good solution 
// basic idea is that calculate occurrence of 1 on every digit position, and then sum them up
int countDigitOne(int n) {
  if (n <= 0) return 0;
  int q=n, x=1, res=0;      
  while (q) {
    int r = q%10; 
    q /= 10;

    res += q * x;   
    if (r == 1) res += n%x + 1;
    if (r > 1) res += x;      // for hundred position x will be 100(100-199) and 
                              // for thousand position x will be 1000(1000-1999)
    x = x*10;
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
