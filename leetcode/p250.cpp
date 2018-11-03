#include<bits/stdc++.h>
using namespace std;

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

class Solution {
public:
  int res;
  // Whether this tree is a uni-value tree.
  bool dfs(TreeNode *root) {
    if (!root) return 1;
    bool left = dfs(root->left);
    bool right = dfs(root->right);
    // If left or right subtree is not a uni-value tree.
    if (left == 0 || right == 0) return 0;
    if (root->left && root->val != root->left->val) return 0;
    if (root->right && root->val != root->right->val) return 0;
    ++res;
    return 1; 
  }

  int countUnivalSubtrees(TreeNode *root) {
    res = 0;
    dfs(root);
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
