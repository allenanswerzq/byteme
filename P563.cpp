/*
563. Binary Tree Tilt My SubmissionsBack To Contest
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
		 1
	   /   \
	  2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

*/
#include <stdio.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    int postorder(TreeNode *root, int& tilt) {
        if (!root) return 0;
		int left_sum = postorder(root->left, tilt);
		int right_sum = postorder(root->right, tilt);
		tilt += abs(left_sum - right_sum);
		return left_sum + right_sum + root->val;
        
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
		postorder(root, tilt);
		return tilt;
    }
};

int main(void) {
	TreeNode root(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
}
