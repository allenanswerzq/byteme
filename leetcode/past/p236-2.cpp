#include <bits/stdc++.h>
using namespace std;

// TODO
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
  bool dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* p) {
  if (!root) return 0;
  path.pb(root);
  if (root == p) return 1;
  if (dfs(root->left, path, p) ||
    dfs(root->right, path, p))
    return 1;
  path.ppb(); 
  return 0;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return root;
  vector<TreeNode*> path1, path2;
  bool aa = dfs(root, path1, p);
  bool bb = dfs(root, path2, q);
  if (!aa || !bb) return nullptr;
  fori (i, 0, sz(path1)) {
    if (path1[i] != path2[i])
    return path1[i - 1]; 
  } 
  return nullptr;
  }
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root==p || root==q) return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  trace(left, right);
  if (left && right) return root;
  return left != nullptr ? left : right; 
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main() {
   return 0;
}
