#include<bits/stdc++.h>
using namespace std;

// TODO
TreeNode* trimBST(TreeNode* root, int L, int R) {
  if (!root) return nullptr;
  if (root->val < L) return trimBST(root->right, L, R);
  if (root->val > R) return trimBST(root->left, L, R);
  TreeNode *cur = new TreeNode(root->val);
  cur->left = trimBST(root->left, L, R);
  cur->right = trimBST(root->right, L, R);
  return cur;
}

int main() {
  return 0;
}
