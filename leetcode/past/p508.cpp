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
int mx;
unordered_map<int, int> mp;
int go(TreeNode *root) {
  if (!root) return 0;
  int sum = root->val;
  sum += go(root->left);
  sum += go(root->right);
  ++mp[sum];
  mx = max(mp[sum], mx);
  return sum;
}

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vi res;
    mp.clear();
    if (!root) return res;
    mx = 0;
    go(root);
    fora (a, mp)
      if (a.se == mx) res.pb(a.fi);
    return res;
  }
};

int main() {
  return 0;
}
