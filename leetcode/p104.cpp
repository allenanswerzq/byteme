#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int main() {
  return 0;
}
