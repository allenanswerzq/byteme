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

// Accepted
// recusive approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return NULL;
  if (p->val<root->val&&root->val<q->val || q->val<root->val&&root->val<p->val)
    return root;        
  if (p->val==root->val || q->val==root->val) return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  if (left) return left;
  return lowestCommonAncestor(root->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val<root->val && q->val<root->val)
    return lowestCommonAncestor(root->left, p, q);
  if (q->val>root && q->val>root->val)
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

// iterative approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode *cur = root;
  while (true) {
    if (p->val<cur->val && q->val<cur->val)
      cur = cur->left;
    else if (p->val>cur->val && q->val>cur->val)
      cur = cur->right;
    else return cur;
  }
}

int main(int argc, char** argv) {
  return 0;
}
