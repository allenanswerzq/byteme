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

// Given a binary tree, count the number of uni-value subtrees.
// A Uni-value subtree means all nodes of the subtree have the same value.
// For example:
// Given binary tree,
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// return 4.
int count = 0;
bool recu(TreeNode* root) { // whether all nodes in a subtree have the given value
  if (root == nullptr) return true;  

  auto left = recu(root->left); 
  auto right = recu(root->right);
  // if left and right substrees are all uni-value substree
  if (left && right 
    && (left==nullptr || left->val==root->val)
    && (right==nullptr || right->val==root->val)) {
    count++;
    return true;
  }
  return false;
}

int countUnivalSubtrees(TreeNode *root) {
  recu(root);
  return count;
}
