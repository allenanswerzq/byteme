#include<bits/stdc++.h>

using namespace std;

// Accepted
// recusive approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return nullptr;
  if (p->val < root->val && root->val < q->val 
    || q->val < root->val && root->val < p->val)
    return root;        
  if (p->val == root->val || q->val == root->val) 
    return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  if (left) return left;
  return lowestCommonAncestor(root->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val < root->val && q->val < root->val)
    return lowestCommonAncestor(root->left, p, q);
  if (q->val > root && q->val > root->val)
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

// iterative approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode *cur = root;
  while (true) {
    if (p->val < cur->val && q->val < cur->val)
      cur = cur->left;
    else if (p->val > cur->val && q->val > cur->val)
      cur = cur->right;
    else return cur;
  }
}

int main(int argc, char** argv) {
  return 0;
}
