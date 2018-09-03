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

// class TreeNode {
// public:
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) {
//     val = x;
//     left = null;
//     right = null;
//   }
// };

void pre(TreeNode *root) {
  if (!root) return;
  cout << root->val << " ";
  pre(root->left);
  pre(root->right);
}

vector<TreeNode*> create(int lo, int hi) {
  vector<TreeNode*> res;
  if (lo > hi) {
  res.pb(null);
  return res;
  }
  if (lo == hi) {
  res.pb(new TreeNode(lo));
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
    res.pb(root);
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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  test(3);
  return 0;
}
