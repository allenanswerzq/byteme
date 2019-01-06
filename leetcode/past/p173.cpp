#include <bits/stdc++.h>
using namespace std;

// Idea: iterative inorder traversal
class BSTIterator {
private:
  stack<TreeNode*> stk;
  void pushAllLeft(TreeNode* root) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
  }
  
public:
  BSTIterator(TreeNode *root) {
    pushAllLeft(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stk.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *top = stk.top(); stk.pop();
    pushAllLeft(top->right);
    return top->val;
  }
};

int main() {
  return 0;
}
