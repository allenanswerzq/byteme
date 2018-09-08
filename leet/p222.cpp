#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int height(TreeNode *root) {
    return root == nullptr ? 0: 1 + height(root->left);
  }

  int countNodes(TreeNode* root) {
    int h = height(root);
    if (h <= 0) return 0;
    if (height(root->right) == h - 1) {
      return (1 << (h - 1)) - 1 + 1 + countNodes(root->right); 
    } else {
      return countNodes(root->left) + 1 + (1 << (h - 2)) - 1; 
    }
    // Never reach here.
    return -1; 
  }

  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int h = 0;
    TreeNode* left = root;
    TreeNode* right = root;
    while (right != nullptr) {
      left = left->left;
      right = right->right;
      h++;
    }
    // Left subtree and right subtree both are complete binary tree
    if (left == nullptr) return ((1 << h) - 1);
    return countNodes(root->left) + 1 + countNodes(root->right);
  }
};

int main(int argc, char** argv) {
  int x = (1 << 5 - 1)
  cout << x << endl;
  return 0;
}
