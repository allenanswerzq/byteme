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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* find_min(TreeNode *root) {
  TreeNode *node = root;
  while (node->left) {
  node = node->left;
  }
  return node;
}

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root) return null;
  if (key < root->val) 
    root->left = deleteNode(root->left, key);
  else if (key > root->val) 
    root->right = deleteNode(root->right, key);
  else {
    if (!root->left) return root->right;
    if (!root->right) return root->left;
    TreeNode *p = find_min(root->right);
    root->val = p->val;
    root->right = deleteNode(root->right, root->val);
  }
  return root;
  }
};

// class Solution {
// public:
//   TreeNode* deleteNode(TreeNode* root, int key) {
//     if (!root) return root;
//     if (root->val > key) root->left = deleteNode(root->left, key);
//     if (root->val < key) root->right = deleteNode(root->right, key);
//     if (root->val == key) {
//       if (!root->left) return root->right;
//       if (!root->right) return root->left;
//       TreeNode* p = find_min(root->right);
//       root->val = p->val;
//       root->right = deleteNode(root->right, p->val);
//     }
//     return root;
//   }
// };

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
