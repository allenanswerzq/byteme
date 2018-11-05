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

int sum = 0;
void travel(TreeNode *root) {
  if (!root) return ;
  travel(root->right);
  sum += root->val;
  root->val = sum;
  travel(root->left);
}

class Solution {
public:
  TreeNode* convertBST(TreeNode* root) {
    travel(root);
    return root;
  }
};

int main() {
  return 0;
}
