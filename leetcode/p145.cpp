#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {    
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    unordered_map<TreeNode*, bool> mp;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *top = stk.top();
      if (top->left && mp.count(top->left)) {
        stk.push(top->left);
        mp[top->left] = true;
      } else if(top->right && mp.count(top->right)) {
        stk.push(top->right);
        mp[top->right] = true;
      } else {
        stk.pop();
        res.push_back(top->val);
      } 

    }
    return res;
  }

  vector<int> postorderTraversal(TreeNode* root) {    
    if (!root) return {};
    vector<int> ret;
    stack<TreeNode*> stk;
    TreeNode *last_visited = nullptr;
    while (!stk.empty() || root) {
      if (root) {
        stk.push(root);
        root = root->left;
      } else {
        TreeNode *top = stk.top();
        if (top->right && top->right != last_visited) {
          root = top->right;
        } else {
          stk.pop();
          ret.push_back(top->val);
          last_visited = top;
          root = nullptr;
        }
      }
    } 
    return ret;
  }
};

int main() {
  return 0;
}
