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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
