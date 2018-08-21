#include<bits/stdc++.h>

using namespace std;


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root==p || root==q) return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  if (left && !right) return left;
  if (!left && right) return right;
  if (left && right) return root;
  return NULL; // never reach here
}

// python version
def lowestCommonAncestor(self, root, p, q):
  if root in (None, p, q): return root
  left, right = (self.lowestCommonAncestor(kid, p, q) 
                  for kid in (root.left, root.right)) 
  return root if left and right else left or right

def lowestCommonAncestor(self, root, p, q):
  subs = [self.lowestCommonAncestor(kid, p, q)
          for kid in (root.left, root.right)]
  return root if all(subs) else max(subs)
