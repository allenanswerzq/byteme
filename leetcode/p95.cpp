#include<bits/stdc++.h>
using namespace std;

void pre(TreeNode *root) {
  if (!root) return;
  cout << root->val << " ";
  pre(root->left);
  pre(root->right);
}

vector<TreeNode*> create(int lo, int hi) {
  vector<TreeNode*> res;
  if (lo > hi) {
    res.push_back(null);
    return res;
  }
  
  if (lo == hi) {
    res.push_back(new TreeNode(lo));
    return res;
  }

  fori (i, lo, hi + 1) {
    vector<TreeNode*> lefts = create(lo, i-1);
    vector<TreeNode*> rights = create(i+1, hi);
    fora (left, lefts) {
      fora (right, rights) {
        TreeNode *root = new TreeNode(i);
        root->left = left;
        root->right = right;
        res.push_back(root);
      }
    }
  }
  return res;
}

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if (n == 0) return res;
    return create(1, n);
  }
};

void test(int n) {
  Solution go;
  vector<TreeNode*> res = go.generateTrees(n);
  fora (r, res) {
    pre(r);
    cout << endl;
  }
}

int main() {
   test(3);
  return 0;
}
