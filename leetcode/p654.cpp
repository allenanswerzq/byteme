#include<bits/stdc++.h>
using namespace std;

TreeNode* build(vector<int>&num, int lo, int hi) {
  int x = INT_MIN;
  int k = 0;
  for (int i=lo; i<=hi; ++i)
    if (num[i] > x) {
      x = num[i];
      k = i;
    }
  TreeNode *root = new TreeNode(x);
  if (k > lo)
    root->left = build(num, lo, k-1);
  if (k < hi)
    root->right = build(num, k+1, hi);
  return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  return build(nums, 0, nums.size()-1);
}

int main() {
  return 0;
}
