#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    deque<TreeNode*> q; 
    q.push_back(root);
    while (sz(q)) {
      ++res;
      int n = sz(q);
      fori (i, 0, n) {
        auto cur = q.front(); q.pop_front();
        if (!cur->left && !cur->right)
          return res; 
        if (cur->left)
          q.push_back(cur->left);
        if (cur->right)
          q.push_back(cur->right);
      }
    }
    return res;
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
