#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vvi res;
void dfs(TreeNode* root, int goal, vi path) {
  if (!root) return;
  if (!root->left && !root->right && root->val == goal) {
  path.pb(root->val);
  res.pb(path);
  return;
  }

  path.pb(root->val);
  dfs(root->left, goal - root->val, path);
  dfs(root->right, goal - root->val, path);
  return;
}

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int goal) {
  res.clear();
  dfs(root, goal, {}); 
  return res;
  }
};
