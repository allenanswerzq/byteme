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

//  sum[i] total sum from nums[0] to nums[i-1]
int pivotIndex(vector<int>& nums) {
  int n = nums.size();
  vector<int> sum(n_1, 0); 

  for (int i=0; i<n; ++i)
  sum[i+1] = sum[i] + nums[i];

  for (int i=0; i<n; ++i) {
  if (sum[i] == sum[n] - sum[i+1]) 
    return i;
  } 
  return -1;
}

int pivotIndex(vector<int>& nums) {
  int n = nums.size();
  vector<int> a(n+1, 0), b(n+1, 0);
  for (int i=0; i<n; ++i) 
  a[i+1] = a[i] + nums[i];  // left side sum of current index i  

  for (int i=n-2; i>=0; --i)
  b[i] = b[i+1] + nums[i+1]; // right side sum of current index i

  for (int i=0; i<=n; ++i) 
  if (a[i] == b[i]) // if left sum equals right sum for current index i
    return i;

  return -1;

}

int main(int argc, char** argv) {
  return 0;
}
