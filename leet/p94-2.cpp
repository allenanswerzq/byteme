#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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
  vi res;
  TreeNode *node = root;
  deque<TreeNode*> stk;
  while (sz(stk) || node != null) {
  if (node) {
  stk.pb(node);
  node = node->left;
  } else {
  TreeNode *p = stk.back(); stk.ppb();
  res.pb(p->val);
  node = p->right;
  }
  }
  return res;
  }
};

void test(TreeNode* root) {
  Solution go;
  vi r = go.inorderTraversal(root);
  pvi(r);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  test(root);
  return 0;
}
