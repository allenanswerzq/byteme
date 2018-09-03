#include<bits/stdc++.h>

using namespace std;

// int res = INT_MIN;
// int dfs(TreeNode* root) {
//     if (!root) return 0;
//     int l = max(0, dfs(root->left));
//     int r = max(0, dfs(root->right));
//     res = max(res, l+r+root->val);
//     // printf("%d %d %d %d\n", root->val, l, r, res);
//     return max(l, r) + root->val; 
// }

// ref: https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
int res = -(1<<31);
int dfs(TreeNode *root) {
  if (!root) return 0;
  int l = dfs(root->left);
  int r = dfs(root->right);
  int max_single = max(max(l, r) + root->val, root->val);
  int max_top = max(max_single, l + r + root->val);
  res = max(res, max_top);
  return max_single;
}

int maxPathSum(TreeNode* root) {
  dfs(root);
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
