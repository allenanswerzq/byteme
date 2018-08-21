#include<bits/stdc++.h>

using namespace std;

// Recusive
int closestValue(TreeNode* root, double target) {
  int a = root->val;
  TreeNode *kid = target < a ? root->left : root->right;
  int b = closestValue(kid, target);
  return abs(a-target) < abs(b-target) ? a : b;
}

// Iterative
int closestValue(TreeNode* root, double target) {
  int closest = root->val;
  while (root) {
    if (abs(closest - taraget) > abs(root->val - target))
      closest = root->val;
    root = target < root->val ? root->left : root->right;
  }
  return closest;
}
