#include<bits/stdc++.h>
using namespace std;


vi res;
int pre;
int cnt;
int mx;

void traverse(TreeNode *root) {
  if (!root) return;
  traverse(root->left);
  if (root->val == pre) ++cnt;
  else cnt = 1;
  if (cnt > mx) {
    mx = cnt;
    res.clear();
    res.pb(root->val);
  } else if (cnt == mx) {
    res.pb(root->val);
  }
  pre = root->val;
  traverse(root->right);
}

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    res.clear();
    if (!root) return res;
    mx = 0;
    cnt = 0;
    pre = nnf;
    traverse(root);
    return res;
  }
};

int main() {
  return 0;
}
