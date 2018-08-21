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
// Consider implement these two helper functions:
// getPredecessor(N), which returns the next smaller node to N.
// getSuccessor(N), which returns the next larger node to N.
// Try to assume that each node has a parent pointer, it makes the problem much easier.
// Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
// You would need two stacks to track the path in finding predecessor and successor node separately.

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
// Max heap
void dfs(TreeNode *root, priority_queue<pair<int,int>> pq, int target, int k) {
    if (root == nullptr) return;
    pq.push(make_pair(abs(target - root->val), root->val));
    if (pq.size() > k)
        pq.pop();   // remove greatest value 
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
// Use two stack to track all elements greater than target and less than target
// Assume target is 2.5 [1, 2, 5,6]
// stk1 (1, 2)
// stk2 (6, 5)
// Then, we can use same idea like merge sort to chose closest k value
int main() {
}
