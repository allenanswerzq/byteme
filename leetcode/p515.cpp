#include<bits/stdc++.h>
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
  deque<TreeNode*> q;
  q.pb(root);
  while (sz(q)) {
    int n = sz(q);
    int mx = nnf;
    fori (i, 0, n) {
    auto cur = q.fr(); q.ppf();
    mx = max(mx, cur->val);
    if (cur->left) q.pb(cur->left);
    if (cur->right) q.pb(cur->right);
    }
    res.pb(mx);
  }
  return res;
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main() {
   return 0;
}
