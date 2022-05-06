/* created   : 2022-05-04 22:22:22
 * accepted  : 2022-05-04 22:22:22
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  int ans = -1e9;

  int dfs(TreeNode* root) {
    if (!root) return -1e9;
    int l = dfs(root->left);
    int r = dfs(root->right);
    int v = root->val;
    ans = max({ans, l, r, v, l + v, r + v, l + r + v});
    return max({l, r, 0}) + v;
  }

  int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    dfs(root);
    return ans;
  }
};
