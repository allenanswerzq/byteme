/* created   : 2022-05-04 16:00:59
 * accepted  : 2022-05-04 16:00:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    vector<TreeNode*> qu;
    qu.push_back(root);
    int m = qu.size();
    int flag = 1;
    int k = 0;
    vector<int> tmp(m);
    for (int i = 0; i < qu.size(); i++) {
      auto cur = qu[i];
      if (flag) {
        tmp[k++] = cur->val;
      }
      else {
        tmp[k--] = cur->val;
      }
      if (cur->left) qu.push_back(cur->left);
      if (cur->right) qu.push_back(cur->right);
      if (i == m - 1) {
        ans.push_back(tmp);
        tmp.resize(qu.size() - m, 0);
        m = qu.size();
        flag ^= 1;
        k = flag ? 0 : tmp.size() - 1;
      }
    }
    return ans;
  }
};
