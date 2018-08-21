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

// TODO
pii dfs(TreeNode* root) {
  if (!root) return {0, 0};
  pii left = dfs(root->left);
  pii right = dfs(root->right);
  pii res;
  res.fi = left.se + right.se + root->val;
  res.se = max(left.fi, left.se) + max(right.fi, right.se);  
  return res;
}

class Solution {
public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    pii res = dfs(root); 
    return max(res.fi, res.se);
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
