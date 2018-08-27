#include<bits/stdc++.h>
using namespace std;

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
