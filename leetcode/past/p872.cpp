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

void dfs(TreeNode* root, vi& path) {
  if (!root) return;
  dfs(root->left, path);
  dfs(root->right, path);
  if (!root->left && !root->right)
  path.push_back(root->val);
}

class Solution {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return 1;
    vi a, b;
    dfs(root1, a);
    dfs(root2, b);
    // pvi(a);
    // pvi(b);
    if (sz(a) != sz(b)) return 0;
    fori (i, 0, sz(a))
      if (a[i] != b[i]) return 0;
    return 1;
  }
};


int main() {
  return 0;
}
