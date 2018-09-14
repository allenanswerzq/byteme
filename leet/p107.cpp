#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
  // dfs approach
  vector<vector<int>> res;
  void dfs(TreeNode* root, int level) {
    if (!root) return;
    if (level == res.size()) {
      res.push_back(vector<int>());
    }
    res[level].push_back(root->val);
    dfs(root->left, level+1);
    dfs(root->right, level+1);
  }

  // another approach
  // res[height-i] = queue[i]
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    dfs(root, 0);
    return vector<vector<int>> (res.rbegin(), res.rend());
  }
};

int main(int argc, char** argv) {
  return 0;
}
