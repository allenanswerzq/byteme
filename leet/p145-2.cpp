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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vi res;
    if (!root) return res; 
    deque<TreeNode*> stk;
    TreeNode *node = root;
    TreeNode *pre = null;
    while (sz(stk) || node) {
      if (node) {
        stk.pb(node);
        node = node->left;
      } else {
        auto cur = stk.bk();
        if (cur->right && pre != cur->right)
          node = cur->right;
        else {
          auto cur = stk.bk(); stk.ppb();
          res.pb(cur->val);
          pre = cur;
          node = null;
        }
      }
    } 
    return res;
  }
};


void test(TreeNode *root) {
  Solution go;
  vi res = go.postorderTraversal(root);
  pvi(res);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  test(root);
  return 0;
}
