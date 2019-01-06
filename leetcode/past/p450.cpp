#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* find_min(TreeNode *root) {
  TreeNode *node = root;
  while (node->left) {
    node = node->left;
  }
  return node;
}

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return null;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
      if (!root->left) return root->right;
      if (!root->right) return root->left;
      TreeNode *p = find_min(root->right);
      root->val = p->val;
      root->right = deleteNode(root->right, root->val);
    }
    return root;
  }
};

int main() {
  return 0;
}
