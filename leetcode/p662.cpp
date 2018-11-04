#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int mx = 0;
    deque<pair<TreeNode*, int>> q;
    q.pb({root, 1});
    while (sz(q)) {
      int n = sz(q);
      int lo = q.fr().se;
      int hi = lo;
      fori (i, 0, n) {
      auto cur = q.fr(); q.ppf();
      TreeNode *node = cur.fi;
      hi = cur.se;
      if (node->left) q.pb({node->left, 2 * hi});
      if (node->right) q.pb({node->right, 2 * hi + 1});
      }
      mx = max(mx, hi - lo + 1);
    }
    return mx;
  }
};

int main() {
  return 0;
}
