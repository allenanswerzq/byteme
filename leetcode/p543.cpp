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

int height(TreeNode* root) {
  return root == null ? 0 : max(height(root->left),
                height(root->right)) + 1;
}

class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int a = diameterOfBinaryTree(root->left);
    int b = diameterOfBinaryTree(root->right);
    int c = height(root->left);
    int d = height(root->right);
    return max(max(a, b), c + d);
  }
};

void test() {
  Solution go;
  int r;
  output(r);
}

int main() {
  return 0;
}
