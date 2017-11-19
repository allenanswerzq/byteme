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

// global variables 
int num;
int res;
void inOrder(TreeNode*root) {
  if (!root) return;
  inOrder(root->left);
  num--;
  if (num == 0) res = root->val;
  inOrder(root->right);
}

int kthSmallest(TreeNode* root, int k) {
  num = k;
  inOrder(root);        
  return res;
}

// 
int inOrder(TreeNode* root, int& k) { // note & symbol
  if (!root) return -1;
  int x = inOrder(root->left, k);
  if (k == 0) return x;           // find kth in left subtree
  if (--k == 0) return root->val; // find kth in root node
  return inOrder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
  return inOrder(root, k);
}

int main(int argc, char** argv) {
  return 0;
}
