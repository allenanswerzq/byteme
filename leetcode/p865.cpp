#include<bits/stdc++.h>
using namespace std;

TreeNode* res;
int mx;

int dfs(TreeNode* root, int depth) {
  if (!root) return depth;
  int a = dfs(root->left, depth + 1);
  int b = dfs(root->right, depth + 1);
  if (a == b && a >= mx) {
    mx = a; res = root;
  }
  return max(a, b);
}

class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if (!root) return nullptr;
    res = nullptr;
    mx = -1;
    dfs(root, 0);
    return res;
  }
};

int main() {
  return 0;
}
