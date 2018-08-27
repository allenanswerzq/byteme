#include<bits/stdc++.h>
using namespace std;

// Recusive 
TreeNode* invertTree(TreeNode* root) {
	if (!root) return NULL;
	TreeNode *left = invertTree(root->left);
	TreeNode *right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

// Iterative 
TreeNode* invertTree(TreeNode* root) {
	if (!root) return NULL;
	queue<TreeNode*> que;
	que.push(root);
	while(!que.empty()) {
		TreeNode *node = que.top(); que.pop();
		swap(node->left, node->right);
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	}
	return root;
}

int main(int argc, char** argv) {
  return 0;
}
