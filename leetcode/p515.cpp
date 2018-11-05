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
  vector<int> largestValues(TreeNode* root) {
    vi res;
    res.clear();
    if (!root) return res;
    deque<TreeNode*> dq;
    dq.pb(root);
    while (sz(dq)) {
      int n = sz(dq);
      int mx = nnf;
      fori (i, 0, n) {
        auto cur = dq.fr(); dq.ppf();
        mx = max(mx, cur->val);
        if (cur->left) dq.pb(cur->left);
        if (cur->right) dq.pb(cur->right);
      }
      res.pb(mx);
    }
    return res;
  }
};

int main() {
  return 0;
}
