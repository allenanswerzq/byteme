#include<bits/stdc++.h>
using namespace std;

class Solution {
public:  
  int res = 0;
  void dfs(TreeNode* root, int path) {
    if (!root) return;

    path = 10 * path + root->val;

    // If current node is leaf node
    if (!root->left && !root->right) {
      res += path;
      return ;
    }

    dfs(root->left, path);
    dfs(root->right, path);
  }

  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    dfs(root, 0); 
    return res;
  }
};

int main() {
  return 0;
}
