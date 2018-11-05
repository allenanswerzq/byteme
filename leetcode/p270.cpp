#include <bits/stdc++.h>
using namespace std;

// Given a non-empty binary search tree and a target value, 
// find the value in the BST that is closest to the target.
// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST
// that is closest to the target.

class Solution {
public:
  // Recusive
  int closestValue(TreeNode* root, double target) {
    int a = root->val;
    TreeNode *kid = target < a ? root->left : root->right;
    int b = closestValue(kid, target);
    return abs(a - target) < abs(b - target) ? a : b;
  }

  // Iterative
  int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    while (root) {
      if (abs(closest - target) > abs(root->val - target))
        closest = root->val;
      root = target < root->val ? root->left : root->right;
    }
    return closest;
  }
};
