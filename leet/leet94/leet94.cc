/* created   : 2022-05-11 12:15:44
 * accepted  : 2022-05-11 12:15:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *p) {
    vector<int> ans;
    vector<TreeNode *> stk;
    while (1) {
      while (p) {
        ans.push_back(p->val);
        stk.push_back(p);
        p = p->left;
      }
      if (stk.empty()) break;
      p = stk.back();
      stk.pop_back();
      p = p->right;
    }
    return ans;
  }

  vector<int> inorderTraversal(TreeNode *p) {
    vector<int> ans;
    vector<TreeNode *> stk;
    while (1) {
      while (p) {
        stk.push_back(p);
        p = p->left;
      }
      if (stk.empty()) break;
      p = stk.back();
      stk.pop_back();
      ans.push_back(p->val);
      p = p->right;
    }
    return ans;
  }

  vector<int> postorderTraversal(TreeNode *p) {
    vector<int> ans;
    vector<TreeNode *> stk;
    TreeNode *pre = nullptr;
    while (1) {
      while (p) {
        stk.push_back(p);
        p = p->left;
      }
      if (stk.empty()) break;
      p = stk.back();
      if (p->right && pre != p->right) {
        p = p->right;
        continue;
      }
      pre = p;
      ans.push_back(p->val);
      stk.pop_back();
      p = nullptr;
    }
    return ans;
  }
};
