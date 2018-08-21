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

int dfs(TreeNode* root, int inp) {
  if (!root) return 0;
  if (root->val != inp) return 0;
  int a = dfs(root->left, inp);
  int b = dfs(root->right, inp);
  return max(a, b) + 1;
}

class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    int a = longestUnivaluePath(root->left);
    int b = longestUnivaluePath(root->right);
    int c = dfs(root->left, root->val);
    int d = dfs(root->right, root->val);
    return max(max(a, b), c + d);
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
