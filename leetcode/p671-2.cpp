#include<bits/stdc++.h>
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
class Solution {
public:
  int findSecondMinimumValue(TreeNode* root) {
  if (!root) return -1;
  int a = findSecondMinimumValue(root->left);
  int b = findSecondMinimumValue(root->right);
  }
};

int main() {
   return 0;
}
