#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vvi res;
    if(!root) return res;
    deque<TreeNode*> q;
    int level = 0;
    q.push_back(root);
    while (sz(q)) {
      int n = sz(q);
      vi tmp;
      ++level;
      fori (i, 0, n) {
        auto cur = q.front(); q.pop_front(); 
        if (level % 2) tmp.push_back(cur->val);
        else tmp.insert(tmp.begin(), cur->val);
        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
      }
      res.push_back(tmp);
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
