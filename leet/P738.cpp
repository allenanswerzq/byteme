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

// TLE 218/302 tests passed
// Naive idea
int monotoneIncreasingDigits(int N) {
  for (int i=N; i>=0; --i) {
  int x = i % 10;
  int y = i / 10;
  while (x && y) {
  int t = y % 10;
  if (t > x) break;
  x = t;
  y /= 10;
  }
  if (y == 0) return i;
  }
  return 0;
}

// Idea: first, find a base nubmer that nearest N and also each bits are same. for example (222)
// Literally change every bits in that number to make it more close to N
int monotoneIncreasingDigits(int N) {
  vector<int> bits;
  for (int t=N; t; t/=10) bits.push_back(t % 10);
  int n = bits.size();
  int ret=0, pre=0;
  for (int i=0; i<n; ++i) {
  for (int k=9; k>=pre; --k) {
  int cur = ret;
  for (int j=i; j<n; ++j) cur = cur*10 + k;
  if (cur <= N) {
  ret = ret*10 +k;
  pre = k;
  break;
  }
  }
  }
  return ret;
}

int monotoneIncreasingDigits(int N) {
  int base=1; // 1 10 100 1000 ...
  int base2=1; // 1 11 111 1111 ...
  for (int i=0; i<9; ++i) {
  base2 += base*10;
  base = base*10;
  }
  int pre=0, ret=0;
  while(base2 > 0) {
  for (int k=9; k>=pre; --k) {
  long long int cur = ret + base2*k;  // Note: overflow might occur here
  if (cur <= N) {
  ret += base * k;
  pre = k;
  break;
  }
  } 
  base2 /= 10;
  base /= 10;
  }
  return ret;
}
