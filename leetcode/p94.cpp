#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(null), right(null) {}
};
 
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vi ret;
    TreeNode *node = root;
    deque<TreeNode*> stk;
    while (sz(stk) || node != null) {
      if (node) {
        stk.push_back(node);
        node = node->left;
      } else {
        TreeNode *p = stk.back(); stk.pop_back();
        ret.push_back(p->val);
        node = p->right;
      }
    }
    return ret;
  }
};

void test() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution go;
  vi r = go.inorderTraversal(root);
  pvi(r);
}

int main() {
 
  test();
  return 0;
}
