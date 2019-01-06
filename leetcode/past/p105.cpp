#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = null;
    right = null;
  }
};

TreeNode* go(vi& aa, vi& bb, int a, int b, int c, int d) {
  trace(a, b, c, d);
  if (a > b || c > d) return null;
  if (a == b && c == d) return new TreeNode(aa[a]);
  TreeNode *root = new TreeNode(aa[a]);  
  int ix = -1;
  fori (i, c, d + 1) {
    if (bb[i] == aa[a]) {
      ix = i;
      break;
    }
  }
  
  if (ix > c) {
    root->left = go(aa, bb, a + 1, a + ix - c, c, ix - 1);
  } else root->left = null; 

  if (ix < d) {
    root->right = go(aa, bb, a + ix - c + 1, b, ix + 1, d);
  } else root->right = null;

  return root;
}

class Solution {
public:
  TreeNode* buildTree(vector<int>& aa, vector<int>& bb) {
    int m, n;
    m = sz(aa), n = sz(bb);
    if (!m || !n || m != n) return null;
    return go(aa, bb, 0, m - 1, 0, n - 1);
  }
};

void pre(TreeNode *root) {
  if (!root) return;
  cout << root->val << " ";
  pre(root->left);
  pre(root->right);
}

void test(vi aa, vi bb) {
  Solution go;
  TreeNode *res = go.buildTree(aa, bb);
  pre(res);
}

int main() {
   test({3,9,20,15,7}, {9,3,15,20,7});
  return 0;
}
