/* created   : 2022-04-13 08:35:06
 * accepted  : 2022-04-13 08:35:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;


// One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

// Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

// It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid.

// For example, it could never contain two consecutive commas, such as "1,,3".
// Note: You are not allowed to reconstruct the tree.
class Solution {
public:
  int k = 1;
  bool ok = true;
  void dfs(TreeNode* root, vector<int>& pre) {
    if (!root) return;
    assert(root);
    // cout << root->val << " " << k << "\n";
    if (k+1 < pre.size() && pre[k] == -1 && pre[k] == pre[k + 1]) {
      k += 2;
      return;
    }
    if (k >= pre.size()) {
      ok = false;
      return;
    }
    root->left = pre[k++] == -1 ? nullptr : new TreeNode(pre[k - 1]);
    dfs(root->left, pre);
    if (k >= pre.size()) {
      ok = false;
      return;
    }
    root->right = pre[k++] == -1 ? nullptr : new TreeNode(pre[k - 1]);
    dfs(root->right, pre);
  }

  bool isValidSerialization(string S) {
    istringstream iss(S);
    string x;
    vector<int> pre;
    while (getline(iss, x, ',')) {
      // cout << x << '\n';
      pre.push_back(x == "#" ? -1 : stoi(x));
    }
    // if (pre[0] == -1) return true;
    auto root = pre[0] == -1 ? nullptr : new TreeNode(pre[0]);
    dfs(root, pre);
    return k == pre.size() && ok;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
