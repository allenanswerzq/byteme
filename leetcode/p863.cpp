#include<bits/stdc++.h>
using namespace std;

// TODO
unordered_map<TreeNode*, TreeNode*> parent;

void dfs(TreeNode* root) {
  if (!root) return;
  parent[root->left] = root;
  parent[root->right] = root;
  dfs(root->left);
  dfs(root->right);
}

class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    parent.clear();
    parent[root] = nullptr;
    dfs(root);

    vi res;
    unordered_set<TreeNode*> visit;
    visit.clear();
    deque<TreeNode*> q;
    q.pb(target);
    visit.insert(target);
    while (sz(q) && k >= 0) {
      int n = sz(q);
      fori (i, 0, n) {
        auto cur = q.fr(); q.ppf();

        if (!visit.count(cur->left) && cur->left) {
          visit.insert(cur->left);
          q.pb(cur->left);
        }

        if (!visit.count(cur->right) && cur->right) {
          visit.insert(cur->right);
          q.pb(cur->right);
        }

        if (!visit.count(parent[cur]) && parent[cur]) {
          visit.insert(parent[cur]);
          q.pb(parent[cur]);
        }

        if (k == 0) res.pb(cur->val);
        // trace(cur->val, k);
        // pvi(res);
      }
      --k;
    }
    return res;
  }
};

int main() {
  return 0;
}
