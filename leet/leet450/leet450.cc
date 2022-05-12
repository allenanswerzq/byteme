/* created   : 2022-05-10 09:38:54
 * accepted  : 2022-05-10 09:38:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    TreeNode** cur = &root;
    TreeNode** p = nullptr;
    while (*cur) {
      int v = (*cur)->val;
      if (v == key) {
        p = cur;
        break;
      }
      else if (key > v) {
        cur = &(*cur)->right;
      }
      else {
        cur = &(*cur)->left;
      }
    }
    if (!p) return root;
    TreeNode* pos = *p;
    if (!(*p)->right) {
      *p = (*p)->left;
    }
    else {
      p = &(*p)->right;
      while ((*p)->left) {
        p = &(*p)->left;
      }
      swap(pos->val, (*p)->val);
      *p = (*p)->right;
    }
    return root;
  }
};
