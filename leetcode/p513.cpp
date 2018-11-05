#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    if (!root) return 0;
    int pre = 0;
    deque<TreeNode*> q;
    q.pb(root);
    while (sz(q)) {
      int n = sz(q);
      fori (i, 0, n) {
        auto cur = q.fr(); q.ppf();
        if (i == 0) pre = cur->val;
        if (cur->left) q.pb(cur->left);
        if (cur->right) q.pb(cur->right);
      }
      if (sz(q) == 0)
      return pre;
    }
    return pre;
  }
};
int main() {
  return 0;
}
