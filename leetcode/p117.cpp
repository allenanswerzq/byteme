#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    deque<TreeLinkNode*> q;
    q.push_back(root);
    while (sz(q)) {
      int n = sz(q);
      fori (i, 0, n) {
        auto cur = q.front(); q.pop_front();
        if (i == n - 1) cur->next = nullptr;
        else cur->next = q.front();

        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
      } 
    }    
    return;
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
