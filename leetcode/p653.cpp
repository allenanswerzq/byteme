#include <bits/stdc++.h>
using namespace std;

map<int, bool> mp;
bool findTarget(TreeNode* root, int k) {
  if (!root) return false;
  if (mp.find(k - root->val) != mp.end())
     return true;
  else mp[root->val] = true;
  bool l, r;
  l = r = false;
  if (root->left)
    l = findTarget(root->left, k);
  if (root->right)
    r = findTarget(root->right, k);
  return  l || r;
}

int main() {
  return 0;
}
