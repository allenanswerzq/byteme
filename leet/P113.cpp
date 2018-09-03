#include<bits/stdc++.h>

bool hasPathSum(TreeNode* root, int sum) {
  if (!root) return false;
  if (!root->left && !root->right && root->val == sum)
  return true;
  return hasPathSum(root->left, sum-root->val) ||
    hasPathSum(root->right, sum-root->val);
}

void bt(vector<vector<int>>& res, vector<int>& ans, TreeNode* root, int sum) {
	if (!root) return;
	ans.push_back(root->val);
	if (!root->left && !root->right && root->val == sum)
		res.push_back(ans);
	dfs(res, ans, root->left, sum - root->val);
	dfs(res, ans, root->right, sum - root->val);
	ans.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<int> ans;
	if (!root) return res;	
	bt(res, ans, root, sum);
	return res;
}

int main() {
}
