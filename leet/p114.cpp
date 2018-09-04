#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    // trace(root, root->val);
    flatten(root->left);     
    flatten(root->right);

    TreeNode *p = root->left;
    TreeNode *q = root->right;
    root->left = null;
    root->right = null;
    root->right = p;
    p = root;
    while (p && p->right) p = p->right;
    p->right = q;
    return ;
  }
};

void pre(TreeNode* root) {
  if (!root) return;
  cout << root->val << " ";
  pre(root->left);
  pre(root->right);
}

void test() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  Solution go;
  go.flatten(root);
  pre(root);
  cout << endl;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  test();
  return 0;
}
