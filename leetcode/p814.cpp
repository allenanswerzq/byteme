#include<bits/stdc++.h>
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
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
  if (!root) return null;    
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  if (!root->left && !root->right && root->val == 0)
    return null;
  return root;
  }
};

int main() {
   return 0;
}
