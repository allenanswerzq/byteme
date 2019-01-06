#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Recusive 
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }

  // Iterative 
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
      TreeNode *node = que.top(); que.pop();
      swap(node->left, node->right);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    return root;
  }
};

int main() {
  return 0;
}
