#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode* build(vi& aa, vi& bb, int sa, int ea, int sb, int eb) {
    if (sa > ea || sb > eb) return nullptr;
    TreeNode* root = new TreeNode(aa[ea]);
    int ix = -1;
    for (int i = sb; i <= eb; ++i)
      if (bb[i] == root->val) {
        ix = i;
        break;
      }

    if (ix > sb)
      root->left = build(aa, bb, sa, ix - sb - 1 + sa, sb, ix - 1);
    else root->left = nullptr;

    if (ix < eb)
      root->right = build(aa, bb, ix - sb + sa, ea - 1, ix + 1, eb); 
    else root->right = nullptr;

    return root;
  }

  TreeNode* buildTree(vector<int>& aa, vector<int>& bb) {
    if (aa.size() == 0 && bb.size() == 0) return nullptr;
    return build(bb, aa, 0, bb.size() - 1, 0, aa.size() - 1);
  }
};

int main() {
  return 0;
}
