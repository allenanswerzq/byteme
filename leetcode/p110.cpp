#include<bits/stdc++.h>
using namespace std;

int height(TreeNode *root) {
  if (!root) return 0;
  return max(height(root->left), height(root->right)) + 1;
}

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (!root) return 1;
    int a = height(root->left);
    int b = height(root->right);
    return isBalanced(root->left) && 
           isBalanced(root->right) &&
           abs (a - b) <= 1;
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
