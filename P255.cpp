#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

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

// You have an array of preorder traversal of Binary Search Tree ( BST). Your program should verify whether it is a correct sequence or not.
// Input: Array of Integer [ Pre-order BST ]
// Output: String “Yes” or “No”

// Use Stack
bool verifyPreorder(vector<int>& preorder) {
  stack<int> stk;
  int root = INT_MIN; // current root value
  for (auto p : preorder) {
    // All value in the right substree should greater than root 
    if (p < root) 
      return false;
    // if p in right substree, find the root node of p 
    while (!stk.empty() && p>stk.top()) {
      root = stk.top();
      stk.pop();
    }
    stk.push(p);
  }
  return true;
}

// Divide and conquer
bool helper(vector<int>& preorder, int lo, int hi, int lower_bound, int higher_bound) {
  if (lo >= hi) return true; 
  int root = preorder[lo];  // current root
  int i = lo;
  while (lo<=hi && preorder[i]<root) {  // find the index of first value greater than current root
    if (preorder[i]<lower_bound || preorder[i]>higher_bound)
      return false;
    i++;
  }
  return helper(preorder, lo+1, i-1, lower_bound, r-1)  // all nodes value in the left subtree should less than current root
        && helper(preorder, i+1, hi, r+1, higher_bound); // all nodes value in the right substree should greater than root value 
}

bool verifyPreorder(vector<int>& preorder) {
  int n = preorder.size();
  return helper(preorder, 0, n-1, INT_MIN, INT_MAX);
}