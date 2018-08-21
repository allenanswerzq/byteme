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

// Use extra space
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> left(n, 1), right(n, 1);          
  for (int i=1; i<n; ++i) 
    left[i] = left[i-1] * nums[i-1];  // left side product of current i
  for (int i=n-2; i>=0; --i)
    right[i] = right[i+1] * nums[i+1]; // right side product of current i
  for (int i=0; i<n; ++i)
    left[i] *= right[i];
  return left;
}

// Dont use extra space
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> product(n, 1);          
  for (int i=1; i<n; ++i) 
    product[i] = product[i-1] * nums[i-1];
  for (int i=n-1, r=1; i>=0; i--) {
    product[i] *= r; 
    r *= nums[i];
  }
  return product;
}
