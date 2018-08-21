#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
TreeNode* inorderSuccessor(TreeNode* root, TreeNode *p) {
	if (!root) return nullptr;	
	if (p->val >= root->val) 
		return inorderSuccessor(root->right, p);
	else {
		TreeNode *left = inorderSuccessor(root->left, p);	
		return left==nullptr ? root : left;	
	}
}
