#include<bits/stdc++.h>
using namespace std;

TreeNode *n1, *n2, *pre;
void inOrder(TreeNode* root) {
  if (!root) return null;
  inOrder(root->left);
  // Visit current node.
  if (pre) {
    if (!n1 && pre->val > root->val) n1 = pre;
    if (n1 && pre->val > root->val) n2 = root;
  }
  pre = root;
  inOrder(root->right);
}

class Solution {
public:
  void recoverTree(TreeNode* root) {
    n1 = n2 = pre = null;
    inOrder(root);
    if (n1 && n2)
      swap(n1->val, n2->val);
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
