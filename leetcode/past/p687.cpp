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

int dfs(TreeNode* root, int inp) {
  if (!root) return 0;
  if (root->val != inp) return 0;
  int a = dfs(root->left, inp);
  int b = dfs(root->right, inp);
  return max(a, b) + 1;
}

class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    int a = longestUnivaluePath(root->left);
    int b = longestUnivaluePath(root->right);
    int c = dfs(root->left, root->val);
    int d = dfs(root->right, root->val);
    return max(max(a, b), c + d);
  }
};

int main() {
  return 0;
}
