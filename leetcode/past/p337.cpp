#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TODO
pii dfs(TreeNode* root) {
  if (!root) return {0, 0};
  pii left = dfs(root->left);
  pii right = dfs(root->right);
  pii res;
  res.fi = left.se + right.se + root->val;
  res.se = max(left.fi, left.se) + max(right.fi, right.se);  
  return res;
}

class Solution {
public:
  int rob(TreeNode* root) {
  if (!root) return 0;
  pii res = dfs(root); 
  return max(res.fi, res.se);
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main() {
   return 0;
}
