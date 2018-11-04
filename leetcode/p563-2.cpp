#include<bits/stdc++.h>
using namespace std;

int res;
int go(TreeNode *root) {
  if (!root) return 0;
  int a = go(root->left);
  int b = go(root->right);
  res += abs(a - b);
  return a + b + root->val;
}

class Solution {
public:
  int findTilt(TreeNode* root) {
  if (!root) return 0;
  res = 0;
  go(root);
  return res;
  }
};

int main() {
   return 0;
}
