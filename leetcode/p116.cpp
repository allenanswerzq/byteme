#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    queue<TreeLinkNode*> que;
    que.push(root);
    while (!que.empty()) {
      int n = que.size();
      for (int i = 0; i < n; ++i) {
        TreeLinkNode* cur = que.front(); que.pop();
        if (i >= 0 && i < n - 1 && n > 1) 
          cur->next = que.front();
        
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
    }
    return ;
  }

  void connect2(TreeLinkNode *root) {
    if (!root) return;
    if (root->left) root->left->next = root->right;
    if (root->right) {
      root->right->next = root->next ? root->next->left : nullptr;
    }
    connect(root->left);
    connect(root->right);
  }

  void connect3(TreeLinkNode *root) {
    if (!root) return;
    TreeLinkNode *start = root, *cur = nullptr;
    while (start->left) {
      cur = start;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next)
          cur->right->next = cur->next->left;
        cur = cur->next;
      }
      start = start->left;
    } 
  }
};

int main(int argc, char** argv) {
  return 0;
}
