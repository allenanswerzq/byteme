#include<bits/stdc++.h>
using namespace std;

#define vs vector<string>

vs binaryTreePaths(TreeNode* root) {
  if (!root) return {};
  if (!root->left && !root->right) return {to_string(root->val)};
  vs ret;  
  vs left = binaryTreePaths(root->left);
  vs right = binaryTreePaths(root->right);
  for (auto s : left) {
  s = to_string(root->val) + "->" + s;
  ret.push_back(s);
  } 
  for (auto s : right) {
  s = to_string(root->val) + "->" + s;
  ret.push_back(s);
  } 
  return ret;
}

int main(int argc, char** argv) {
  return 0;
}