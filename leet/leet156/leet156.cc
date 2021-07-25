/* created   : 2020-09-29 15:47:43
 * accepted  : 2020-09-29 15:47:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

// Description
// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

// Have you met this question in a real interview?
// Example
// Example1

// Input: {1,2,3,4,5}
// Output: {4,5,2,#,#,3,1}
// Explanation:
// The input is
//     1
//    / \
//   2   3
//  / \
// 4   5
// and the output is
//    4
//   / \
//  5   2
//     / \
//    3   1
// Example2

// Input: {1,2,3,4}
// Output: {4,#,2,3,1}
// Explanation:
// The input is
//     1
//    / \
//   2   3
//  /
// 4
// and the output is
//    4
//     \
//      2
//     / \
//    3   1

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param root: the root of binary tree
   * @return: new root
   */
  TreeNode * upsideDownBinaryTree(TreeNode * root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;
    assert(root->left);
    auto left = upsideDownBinaryTree(root->left);
    if (root->right) {
        root->left->left = root->right;
    }
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;
    return left;
  }
};

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
