#include<bits/stdc++.h>
using namespace std;

// Accepted
// But not O(h) memory
class BSTIterator {
private:
  vector<int> stk;
public:
  void inOrder(TreeNode *root, vector<int>& stk) {
    if (!root) return;
    inOrder(root->left, stk);
    stk.push_back(root->val);
    inOrder(root->right, stk);
  }

  BSTIterator(TreeNode *root) {
    inOrder(root, stk);     
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
     return !stk.empty(); 
  }

  /** @return the next smallest number */
  int next() {
     int x = stk.front();
     stk.earse(stk.begin());
     return x; 
  }
};

// idea: iterative inorder traversal
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
    TreeNode *x = stk.top();
    stk.pop();
    pushAllLeft(x->right);
    return x->val;
  }
};

int main(int argc, char** argv) {
  return 0;
}
