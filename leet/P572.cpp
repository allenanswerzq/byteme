#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

bool isSameTree(TreeNode*n, TreeNode* m) {
	bool left, right;
	/*
	if (!n) {
		if (!m) return true;
		else return false;
	}
	if (!m) {
		if (!n) return true;
		else return false;
	}*/
	// Post Order
	// of course can write Prev Order
	if (!n && !m) return true;
	if (!n || !m) return false;
	left = isSameTree(n->left, m->left);
	right = isSameTree(n->right, m->right);
	if (left && right) {
		if (n->val == m->val) return true;
		else return false;
	}
	return false;
}
bool isSubTree(TreeNode* s, TreeNode* t)
{
	if (!s) return false;
	if (isSameTree(s, t)) return true;
	/*if (isSubTree(s->left, t)) return true;
	if (isSubTree(s->right, t)) return true;
	return false;*/
	return isSubTree(s->left, t) || isSubTree(s->right, t);	
}

int main()
{
	TreeNode s(3);
	s.left = new TreeNode(4);
	s.right = new TreeNode(5);
	s.left->left = new TreeNode(1);
	s.left->right = new TreeNode(2);
	s.left->left->left = new TreeNode(8);
	
	
	TreeNode m(4);
	m.left = new TreeNode(1);
	m.right = new TreeNode(2);

	TreeNode t(4);
	t.left = new TreeNode(1);
	t.right = new TreeNode(2);
	cout << (isSubTree(&s, &t) ? "True" : "False") ;
	return 0;
}
