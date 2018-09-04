#include<bits/stdc++.h>
using namespace std;

TreeNode *pre;
bool dfs(TreeNode *root) {
  if (!root) return 1;
  if (!dfs(root->left)) return 0;
  if (pre && pre->val >= root->val) return 0;
  pre = root;
  if (!dfs(root->right)) return 0;
  return 1;
}

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return 1; 
    pre = null;
    return dfs(root);
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
