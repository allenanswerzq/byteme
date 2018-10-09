#include<bits/stdc++.h>
using namespace std;

bool dfs(TreeNode* root, int goal) {
  if (!root) return 0;
  if (!root->left && !root->right && root->val == goal)
    return 1;  

  if (dfs(root->left, goal - root->val) ||
      dfs(root->right, goal - root->val))
    return 1;
  return 0;
}

class Solution {
public:
  bool hasPathSum(TreeNode* root, int goal) {
    return dfs(root, goal);  
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
