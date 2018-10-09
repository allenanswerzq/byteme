#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

vvi res;
void dfs(TreeNode* root, int goal, vi& path) {
  if (!root) return;
  if (!root->left && !root->right && root->val == goal) {
    path.push_back(root->val);
    res.push_back(path);
    path.pop_back();
    return;
  }

  path.push_back(root->val);
  dfs(root->left, goal - root->val, path);
  path.pop_back();

  path.push_back(root->val);
  dfs(root->right, goal - root->val, path);
  path.pop_back();
  return;
}

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int goal) {
    res.clear();
    vi path;
    dfs(root, goal, path); 
    return res;
  }
};
