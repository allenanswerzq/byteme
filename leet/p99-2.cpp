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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

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
