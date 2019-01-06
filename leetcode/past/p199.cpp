#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    vector<TreeNode*> que;   
    TreeNode *last = root;
    que.push_back(root);
    while (!que.empty()) {
      TreeNode *front = que.front();
      que.erase(que.begin());
      if (front->left) que.push_back(front->left);
      if (front->right) que.push_back(front->right);
      if (front == last) {
        res.push_back(last->val);   
        // Note: how can i know the last node of each level?
        last = que.back();
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
