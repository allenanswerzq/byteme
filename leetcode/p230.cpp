#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int num;
  int res;
  void inOrder(TreeNode*root) {
    if (!root) return;
    inOrder(root->left);
    num--;
    if (num == 0) res = root->val;
    inOrder(root->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    num = k;
    inOrder(root);
    return res;
  }

  int inOrder(TreeNode* root, int& k) {
    if (!root) return -1;
    int x = inOrder(root->left, k);
    if (k == 0) return x;
    if (--k == 0) return root->val;
    return inOrder(root->right, k);
  }

  int kthSmallest(TreeNode* root, int k) {
    return inOrder(root, k);
  }
};

int main() {
  return 0;
}
