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

bool same(TreeNode *s, TreeNode *t) {
  if (!s) return t == null;
  if (!t) return s == null;
  if (s->val != t->val) return 0;
  if (same(s->left, t->left) && 
    same(s->right, t->right))
  return 1;
  return 0;
}

class Solution {
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
  if (!s) return t == null;
  if (s->val == t->val)
    if (same(s, t)) return 1;
  return isSubtree(s->left, t) || 
       isSubtree(s->right, t);
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
