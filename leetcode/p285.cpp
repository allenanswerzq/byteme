#include<bits/stdc++.h>
using namespace std;

// Given a binary search tree and a node in it, 
// find the in-order successor of that node in the BST.

class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode *ret = nullptr;
    while (root) {
      if (p->val >= root->val) {
        root = root->right;
      } else {
        ret = root;
        root = root->left;    
      }
    }
    return ret;
  }

  TreeNode* inorderSuccessor2(TreeNode* root, TreeNode *p) {
    if (!root) return nullptr;  
    if (p->val >= root->val) 
      return inorderSuccessor(root->right, p);
    else {
      TreeNode *left = inorderSuccessor(root->left, p); 
      return left == nullptr ? root : left; 
    }
  }
}
