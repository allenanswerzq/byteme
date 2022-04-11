/* created   : 2020-08-23 20:58:09
 * accepted  : 2022-04-11 09:20:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

struct TreeNode {
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode() {}
  TreeNode(int x) : val(x) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}

  static int NIL;

  // [1,2,3,4,5,null,6,7,8,9,null]
  static TreeNode* create(const vector<int> & v) {
    if (v.empty()) return nullptr;
    vector<TreeNode*> qu;
    auto root = new TreeNode(v[0]);
    qu.push_back(root);
    int k = 1;
    for (int i = 0; i < qu.size(); i++) {
      if (!qu[i]) continue;
      trace(i, qu[i], k);
      if (k < v.size()) {
        auto l = (v[k] == TreeNode::NIL ? nullptr : new TreeNode(v[k]));
        qu[i]->left = l;
        qu.push_back(l);
        k++;
      }
      if (k < v.size()) {
        auto r = (v[k] == TreeNode::NIL ? nullptr : new TreeNode(v[k]));
        qu[i]->right = r;
        qu.push_back(r);
        k++;
      }
    }
    return root;
  }

  void traverse(TreeNode* root, vector<int> & ans) {
    ans.push_back(root ? root->val : NIL);
    if (root->left) traverse(root->left, ans);
    if (root->right) traverse(root->right, ans);
  }

  vector<int> serialize() {
    vector<int> ans;
    traverse(this, ans);
    return ans;
  }
};

int TreeNode::NIL = 1e9;

void test(const vector<int>& v) {
  TreeNode* n = TreeNode::create(v);
  if (n) {
    trace(n->serialize());
  }
}

void solve() {
  // test({});
  test({1, TreeNode::NIL, 2, TreeNode::NIL, 3});
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
