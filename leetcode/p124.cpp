#include <bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  // Ref: https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

  // For each node there can be four ways that the max path goes through the node:
  // 1. Node only
  // 2. Max path through Left Child + Node
  // 3. Max path through Right Child + Node
  // 4. Max path through Left Child + Node + Max path through Right Child

  int res = -(1 << 30);
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
};

int main() {
  return 0;
}
