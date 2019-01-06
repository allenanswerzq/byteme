#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
vector<int> a[N];
bool leaf[N];
int visit[N];

class Solution {
public:
  void traverse(TreeNode* cur, int p) {
    if (cur == nullptr) return;
    if (p > 0) {
      a[p].push_back(cur->val);
      a[cur->val].push_back(p);
    }
    if (cur->left == nullptr && cur->right == nullptr) leaf[cur->val] = true;
    traverse(cur->left, cur->val);
    traverse(cur->right, cur->val);
  }

  int findClosestLeaf(TreeNode* root, int k) {
    for (int i = 0; i < N; ++i) {
      a[i].clear();
      leaf[i] = false;
      visit[i] = -1;
    }
    traverse(root, -1);
    queue<int> dq;
    dq.push(k);
    visit[k] = 0;
    while (!dq.empty()) {
      int u = dq.front(); dq.pop();

      if (leaf[u]) return u;
      for (auto& v : a[u]) {
        if (visit[v] >= 0) continue;
        dq.push(v);
        //visit[v] = visit[u] + 1;
        visit[v] = 1;
      }
    }
    return -1;
  }
};
