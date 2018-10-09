#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  // Recusive approach
  bool go(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return q->val == q->val && 
           go(p->left, q->right) && 
           go(p->right, q->left);
  }

  bool isSymmetric(TreeNode* root) {
    return root == nullptr || go(root->left, root->right);
  }

  // Iterative approach
  bool isSymmetric2(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q1, q2;

    TreeNode *left, *right;
    q1.push(root->left);
    q2.push(root->right);

    while (q1.size() && q2.size()) {
      left = q1.front(); q1.pop();
      right = q2.front(); q2.pop();
      if (!left && !right) continue;
      if (!left || !right) return false; 
      if (left->val != right->val) return false;
      q1.push(left->left);
      q1.push(left->right);
      q2.push(right->right);
      q2.push(right->left);
    }
    return true;
  }
};

int main(int argc, char** argv) {
  return 0;
}
