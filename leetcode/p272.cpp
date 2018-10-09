#include<bits/stdc++.h>
using namespace std;

// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

// Hint:

// 1. Consider implement these two helper functions:
// 　　i. getPredecessor(N), which returns the next smaller node to N.
// 　　ii. getSuccessor(N), which returns the next larger node to N.
// 2. Try to assume that each node has a parent pointer, it makes the problem much easier.
// 3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
// 4. You would need two stacks to track the path in finding predecessor and successor node separately.

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution2 {
public:
  // Max heap
  void dfs(TreeNode *root, priority_queue<pair<int,int>> pq, int target, int k) {
    if (root == nullptr) return;
    pq.push(make_pair(abs(target - root->val), root->val));
    // Remove greatest value
    if (pq.size() > k) 
      pq.pop();    
    dfs(root->left, pq, target, k);
    dfs(root->right, pq, target, k);
  }

  vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> ret;
    dfs(root, pq, target, k);
    while (!pq.empty()) {
      ret.push_back(pq.top().second);
      pq.pop();
    }
    return ret;
  }
};

class Solution {
public:
  vi closestKValues(TreeNode* root, double target, int kk) {
    vi res;
    inorder(root, target, kk, res);
    return res;
  }

  void inorder(TreeNode* root, double target, int kk, vi& res) {
    if (!root) return;
    inorder(root->left, target, kk, res);

    if (sz(res) < kk) {
      res.push_back(root->val);
    } else if (abs(root->val - target) < abs(res[0] - target)) {
      res.erase(res.begin());
      res.push_back(root->val);
    } else {
      return;
    }

    inorder(root->right target, kk, res);
  }
};

// Use two stack to track all elements greater than target and less than target
// Assume target is 2.5 [1, 2, 5, 6]
// stk1 (1, 2)
// stk2 (6, 5)
// Then, we can use same idea like merge sort to chose closest k value

int main() {
  return 0;
}

