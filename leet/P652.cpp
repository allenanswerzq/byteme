#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// TODO
map<TreeNode*, string> mp;
map<string, vector<TreeNode*>> res;

void dfs(TreeNode* root) {
  if (!root) return;
  dfs(root->left);
  dfs(root->right);
  // represent current node's tree into a unique stirng 
  // so two same strings mean two same tree
  mp[root] = '(' + mp[root->left] + to_string(root->val) + mp[root->right] + ')';
  // put all same trees into a vector
  res[mp[root]].push_back(root);
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {        
  mp[NULL] = "";
  vector<TreeNode*> ret;
  dfs(root);
  for (auto it: res) {
    if (it.second.size() > 1) 
      ret.push_back(it.second[0]);
  }
  return ret;
}

int main(int argc, char** argv) {
  return 0;
}
