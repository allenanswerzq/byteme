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

bool same(TreeNode *s, TreeNode *t) {
  if (!s) return t == null;
  if (!t) return s == null;
  if (s->val != t->val) return 0;
  if (same(s->left, t->left) && same(s->right, t->right))
    return 1;
  return 0;
}

class Solution {
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return t == null;
    if (s->val == t->val)
      if (same(s, t)) return 1;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};

int main() {
  return 0;
}
